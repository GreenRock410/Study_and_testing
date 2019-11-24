#pragma once

namespace study {
namespace multi_threads {
namespace exit_thread {

	class test
	{
	public:
		test(int ID);
		~test();

	private:
		int m_id{ 0 };
	};

	void exit_thread_destructors();

}
}
}
