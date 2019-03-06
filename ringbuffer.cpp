#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MyCircularQueue {
	public:
		MyCircularQueue(int k) {
			ringbuf.resize(k);
			capacity = k;
			wr_idx = 0;
			rd_idx = 0;
		}

		bool enQueue(int value) {
			if (isFull())
				return false;
			ringbuf[wr_idx] = value;
			wr_idx++;
			wr_idx %= capacity;
			cout << "enqueue , wr_idx " << wr_idx << endl;
			return true;
		}

		bool deQueue() {
			if (isEmpty())
				return false;
			rd_idx++;
			rd_idx %= capacity;
			cout << "dequeue , rd_idx " << rd_idx << endl;
			return true;
		}

		bool isEmpty() {
			return wr_idx == rd_idx;
		}

		bool isFull() {
			if (isEmpty())
				return false;
			if ((wr_idx + 1) % capacity == rd_idx)
				return true;
			return false;
		}
	private:
		int capacity;
		int wr_idx;
		int rd_idx;
		vector <int> ringbuf;
};

int main(int argc, char **argv)
{
	MyCircularQueue circularQueue(3); // set the size to be 3
	circularQueue.enQueue(1);  // return true
	circularQueue.enQueue(2);  // return true
	circularQueue.enQueue(3);  // return true
	bool ret = circularQueue.enQueue(4);
	cout << "enqueue fourth elem result is " << ret << endl;  // return false, the queue is full
	ret = circularQueue.isFull();
	cout << "is ring buffer full ? " << ret << endl;  // return true
	ret = circularQueue.deQueue();  // return true
	cout << "dequeue " << ret << endl;
	ret =circularQueue.enQueue(4);  // return true
	cout << "enqueu " << ret << endl;
	ret = circularQueue.deQueue();  // return true
	cout << "dequeue " << ret << endl;
	ret = circularQueue.deQueue();  // return true
	cout << "dequeue " << ret << endl;
	ret = circularQueue.deQueue();  // return true
	cout << "dequeue " << ret << endl;
	ret =circularQueue.enQueue(5);  // return true
	cout << "enqueu " << ret << endl;
	ret = circularQueue.deQueue();  // return true
	cout << "dequeue " << ret << endl;

	exit(EXIT_SUCCESS);
}
