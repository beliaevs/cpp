#pragma once

template<typename T>
class TestList
{
private:
	struct Node
	{
		Node(const T& i_data, Node* i_next = nullptr) : data(i_data), next(i_next) {}
		Node(T&& data, Node* i_next = nullptr) : data(std::move(data)), next(i_next) {}

		T data;
		Node* next;
	};

public:
	class const_iterator
	{
	public:
		const_iterator(TestList::Node* i_node = nullptr): node(i_node) {}
		const T& operator* () const
		{
			return node->data;
		}
		const_iterator operator++()
		{
			node = node->next;
			return const_iterator(node);
		}
		bool operator==(const const_iterator& i_other) const
		{
			return node == i_other.node;
		}

		bool operator!=(const const_iterator& i_other) const
		{
			return node != i_other.node;
		}

		explicit operator bool() const
		{
			return node != nullptr;
		}
	private:
		Node* node = nullptr;
	};

	class iterator
	{
		friend class TestList;
	public:
		iterator(TestList::Node* i_node = nullptr): node(i_node) 
		{}

		T& operator* ()
		{
			return node->data;
		}

		iterator& operator++()
		{
			node = node->next;
			return *this;
		}

		bool operator==(const iterator& i_other) const
		{
			return node == i_other.node;
		}

		bool operator!=(const iterator& i_other) const
		{
			return node != i_other.node;
		}

		explicit operator bool() const
		{
			return node != nullptr;
		}

		private:
		TestList::Node* node = nullptr;
	};

	TestList() = default;

	TestList(const TestList& i_other)
	{
		Node* src = i_other.head;
		Node** dst = &head;

		while (src != nullptr)
		{
			*dst = new Node(*src);
			dst = &(*dst)->next;
			src = src->next;
		}
	}

	TestList(TestList&& other) noexcept: head(std::move(other.head)) 
	{
		other.head = nullptr;
	}

	TestList& operator=(const TestList& i_rhs)
	{
		if (this == &i_rhs)
			return *this;

		TestList(i_rhs).swap(*this);
		return *this;
	}

	TestList& operator=(TestList&& rhs) noexcept
	{
		if (this == &rhs)
			return *this;

		head = rhs.head;
		rhs.head = nullptr;
		return *this;
	}

	TestList(int i_count, const T& i_val)
	{
		for (int i = 0; i < i_count; ++i)
		{
			push_front(i_val);
		}
	}

	TestList(std::initializer_list<T> elements)
	{
		Node** cur = &head;
		for (const auto& e : elements)
		{
			*cur = new Node(e);
			cur = &((*cur)->next);
		}
	}

	~TestList()
	{
		clear();
	}

	T& front()
	{
		return head->data;
	}

	const T& front() const 
	{
		return head->data;
	}

	iterator begin() noexcept
	{
		return iterator(head);
	}

	iterator end() noexcept
	{
		return iterator();
	}

	const_iterator begin() const noexcept
	{
		return const_iterator(head);
	}

	const_iterator end() const noexcept
	{
		return const_iterator();
	}

	void push_front(const T& i_val)
	{
		head = new Node(i_val, head);
	}

	void push_front(T&& val)
	{
		head = new Node(std::move(val), head);
	}

	template<typename... Ts>
	void emplace_front(Ts&&... args)
	{
		head = new Node(T(std::forward<Ts>(args)...), head);
	}

	void pop_front() noexcept
	{
		Node* tmp = head->next;
		delete head;
		head = tmp;
	}

	void clear() noexcept
	{
		while (!empty())
		{
			pop_front();
		}
	}

	bool empty() const noexcept
	{
		return head == nullptr;
	}

	void swap(TestList& other) noexcept
	{
		std::swap(head, other.head);
	}

	iterator insert_after(iterator pos, const T& i_val)
	{
		Node* afterPos = pos.node->next;
		Node* newNode = new Node(i_val, afterPos);
		pos.node = newNode;
		return iterator(newNode);
	}

	iterator erase_after(iterator pos)
	{
		Node* junk = pos.node->next;
		pos.node->next = junk->next;
		delete junk;
		return iterator(pos.node->next);
	}

	void reverse() noexcept
	{
		Node* current = head;
		head = nullptr;

		while (current != nullptr)
		{
			Node* next = current->next;
			current->next = head;
			head = current;
			current = next;
		}
	}

private:
	Node* head = nullptr;
};
