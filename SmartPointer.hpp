#pragma once

#include <cassert>

struct Expression
{
	virtual double evaluate() const = 0;
	virtual ~Expression() {}
};

struct Number: public Expression
{
	Number(double value): value(value) {}
	double evaluate() const { return value; }

private:
	double value;
};

struct BinaryOperation: Expression
{
	BinaryOperation(Expression const * left, char op, Expression const * right) : left(left), op(op), right(right) {}
	double evaluate() const { 
		double t = left->evaluate();
		switch(op) {
			case '+':
				t += right->evaluate();
				break;
			case '-':
				t -= right->evaluate();
				break;
			case '*':
				t *= right->evaluate();
				break;
			default:
				t /= right->evaluate();
				break;
		}
		return t; 
	}
	~BinaryOperation() {
		delete left;
		delete right;
	}

private:
	Expression const * left;
	Expression const * right;
	char op;
};

struct FunctionCall;
struct Variable;

struct ScopedPtr {
	explicit ScopedPtr(Expression *ptr = 0) {
		this->ptr_=ptr;
	}
	~ScopedPtr() {
		delete  ptr_;
	}
	Expression* get() const {
		return ptr_;
	}
	Expression* release() {
		Expression * ptr = this->ptr_;
		this->ptr_ = NULL;
		return ptr;
	}
	void reset(Expression *ptr = 0) {
		delete this->ptr_;
		this->ptr_ = ptr;
	}
	Expression& operator*() const {
		return *ptr_;
	}
	Expression* operator->() const {
		return ptr_;
	}
private:
	ScopedPtr& operator=(const ScopedPtr & other) {}
	ScopedPtr(const ScopedPtr & other) {}
	Expression *ptr_;
};

struct SharedPtr {
	explicit SharedPtr(Expression *ptr = 0) {
		if(ptr == 0) {
			p_cnt = 0;
		} else {
			p_cnt = new size_t(1);
		}
		this->ptr = ptr;
	}
	SharedPtr(const SharedPtr& other) {
		if (other.get() == 0) {
			p_cnt = 0;
		} else {
			p_cnt = other.get_counter();
			incr();
		}
		ptr = other.get();
	}
	SharedPtr& operator=(const SharedPtr& other) {
		if(ptr != other.get()) {
			if(ptr != 0)
				decr();
			if(other.get() != 0) {
				ptr = other.get();
				p_cnt = other.get_counter();
				incr();
			} else {
				ptr = 0;
				p_cnt = 0;
			}
		}
		return *this;
	}
	~SharedPtr() {
		decr();
	}
	void reset(Expression *ptr = 0) {
		decr();
		if(ptr != 0) {
			p_cnt = new size_t(1);
			this->ptr = ptr;
		} else {
			this->p_cnt = 0;
			this->ptr = 0;
		}
	}
	Expression * get() const {
		if (ptr) {
			return ptr;
		}
		return 0;
	}
	size_t * get_counter() const {
		return p_cnt;
	}
	size_t count() const {
		if (ptr) {
			return *p_cnt;
		}
		return 0;
	}
	bool empty() const {
		return !get();
	}
	Expression & operator *() const {
		assert(get());
		return *get();
	}
	Expression * operator ->() const {
		assert(ptr);
		return ptr;
	}

private:
	void incr() {
		if (ptr) {
			++*p_cnt;
		}
	}
	void decr() {
		if(ptr)
			--*p_cnt;
		if (ptr && *p_cnt == 0) {
			delete ptr;
			ptr = 0;
			delete p_cnt;
			p_cnt = 0;
		}
	}

	Expression *ptr;
	size_t *p_cnt;
};
