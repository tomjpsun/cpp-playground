#include <future>
#include <iostream>
#include <deque>
#include <functional>
#include <random>

using namespace std;

int Factorial(int N)
{

	int res = 0;
	for (int loop = 0; loop < 100000; loop++) {
		res=1;
		for(int i=N;i>1;i--)
			res*=i;
	}
	std::cout << __func__ << "(" << N << ") = " << res << endl;
	return res;
}

template <typename TaskType>
class task_queue_manager
{
	std::deque<std::packaged_task<TaskType>> task_queue;
	// mutex used by condition variable
	std::mutex mu;
	// conditional variable protect task_queue
	std::condition_variable cond;
	// the way of using thread:
	//     std::thread (&task_queue_manager::thread_func, task_queue_manager());
public:
	void thread_func() {
		std::packaged_task<TaskType>t;
		{
			//使用condition_variable，lock的方法必須為unique_lock
			std::unique_lock<std::mutex> locker(mu);
			//使用lambda function來指示當容器為空，則不執行任何動作。
			cond.wait(locker,[&](){return !task_queue.empty();});
			t=std::move(task_queue.front());
			task_queue.pop_front();
		}
		t();
	}

	int invoke_task(std::function<TaskType> f) {
		std::thread thread(&task_queue_manager::thread_func, this);
		std::packaged_task<TaskType> t(f);
		std::future<int> fu = t.get_future();
		// enqueue task
		{
			std::lock_guard<std::mutex> locker(mu);
			task_queue.push_back(std::move(t));
		}
		// asnychronous execute task
		cond.notify_one();
		// wait for task result
		int retval = fu.get();
		thread.join();
		return retval;
	}
};

void spawn(task_queue_manager<int()>& manager)
{
	 std::random_device rd;
	 std::default_random_engine gen = std::default_random_engine(rd());
	 std::uniform_int_distribution<int> dis(1,10);

	 std::function<int()> f(std::bind(Factorial,dis(gen)));
	 manager.invoke_task(f);
}

void run_task_q()
{
	task_queue_manager<int()> manager;
	for (int loop = 0; loop < 100; loop++) {
		std::cout << "spawn(" << loop << ")" << endl;;
		std::thread t1(spawn, std::ref(manager));
		std::thread t2(spawn, std::ref(manager));
		std::thread t3(spawn, std::ref(manager));
		std::thread t4(spawn, std::ref(manager));
		t1.join();
		t2.join();
		t3.join();
		t4.join();
	}
}
