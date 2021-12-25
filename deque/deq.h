template <typename T>
class deque {
	struct node {
		T x;
		node *l, *r;
		node() : x(0), l(nullptr), r(nullptr) {}
	};
private:
	int cnt;
	node *head, *tail;
public:
	node* t = new node();
	deque() {
		head = new node();
		tail = new node();
	}
	deque(const deque &other) {
		this->cnt = other.getCount();
		this->head = other.getHead();
		this->tail = other.getTail();
	}
	node* getHead() {
		return head;
	}
	node* getTail() {
		return tail;
	}
	void push_front(T x) {
		if (cnt == 0) {
			head->x = tail->x = x;
		}
		else {
			t = new node();
			t->x = x;
			t->r = head;
			head->l = t;

			head = t;
			if (cnt == 1) {
				tail->l = head;
			}
		}
		cnt++;
	}
	void pop_front() {
		if (cnt == 0) throw std::exception("Error! Empty deque!");
		t = new node();
		t = head->r;
		
		head = new node();
		if (cnt == 1) tail = new node();
		cnt--;
		if (cnt == 1) {
			tail->l = nullptr;
		}
		if (cnt > 0) {
			head = t;
			head->l = nullptr;
		}
	}
	void push_back(T x) {
		if (cnt == 0) {
			head->x = x;
			tail->x = x;
		}
		else {
			t = new node();
			t->x = x;
			t->l = tail;
			tail->r = t;

			tail = t;

			if (cnt == 1) {
				head->r = tail;
			}
		}
		cnt++;
	}
	void pop_back() {
		if (cnt == 0) throw std::exception("Error! Empty deque!");
		t = new node();
		t = tail->l;
		tail = new node();
		if (cnt == 1) head = new node();
		cnt--;
		if (cnt == 1) {
			head->r = nullptr;
		}
		if (cnt > 0) {
			tail = t;
			tail->r = nullptr;
		}
	}
	int getCount() {
		return cnt;
	}
	void print() {
		if (cnt == 0) {
			std::cout << "Empty deque!\n";
		}
		else {
			for (const node* i = head; i != nullptr; i = i->r) {
				std::cout << i->x << " ";
			}
			std::cout << "\n";
		}
	}
	void delDeque() {
		t = new node();
		while (head != nullptr) {
			t = head;
			head = head->l;
			delete t;
		}
		tail = nullptr;
	}
	deque operator = (deque d) {
		return deque(d);
	}
	~deque() {
		delDeque();
	}
};