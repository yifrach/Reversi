
#include <unistd.h>
#include "../include/ThreadPool.h"
#define threadCount 5
ThreadPool::ThreadPool(int threadsNum) : stopped(false) {
	threads = new pthread_t[threadsNum];
	for (int i = 0; i < threadsNum; i++) {
		pthread_create(threads + i, NULL, execute, this);
	}
	pthread_mutex_init(&lock, NULL);
}

void* ThreadPool::execute(void *arg) {
	ThreadPool *pool = (ThreadPool *)arg;
	pool->executeTasks();
}
void ThreadPool::addTask(Task *task) {
	tasksQueue.push(task);
}

void ThreadPool::executeTasks() {
	while (!stopped) {
		pthread_mutex_lock(&lock);
		if (!tasksQueue.empty()) {
			Task* task = tasksQueue.front();
			tasksQueue.pop();
			pthread_mutex_unlock(&lock);
			task->execute();
		}
		else {
			pthread_mutex_unlock(&lock);
			sleep(1);
		}
	}
}

// Terminating our thread pool
void ThreadPool::terminate() {
	pthread_mutex_destroy(&lock);
	this->stopped = true;
	// Closing each thread
	for (int i = 0; i < threadCount; i++ ) {
		pthread_join(threads[i], NULL);
		pthread_cancel(threads[i]);
	}
}

ThreadPool::~ThreadPool() {
	delete[] threads;
}
