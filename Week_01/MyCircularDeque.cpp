class MyCircularDeque {

private:
    int beginindex_;
    int endindex_;
    int curcount_;
    int* parr_;
    int maxcount_;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k)    
    : beginindex_(0)
    , endindex_(0)
    , curcount_(0)
    , maxcount_(k)
    {
        parr_ = new int[maxcount_];
        memset(parr_, 0, maxcount_);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())
            return false; 
        beginindex_ = (beginindex_ - 1 + maxcount_) % maxcount_;
        parr_[beginindex_] = value;

        curcount_++;
        return true; 
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())
            return false;
 
        parr_[endindex_] = value;
        endindex_ = (endindex_ + 1) % maxcount_;
        curcount_++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())
            return false;
        parr_[beginindex_] = 0;
        beginindex_ = (beginindex_ + 1) % maxcount_;
        curcount_--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())
            return false;
        endindex_ = (endindex_ - 1 + maxcount_) % maxcount_;
        parr_[endindex_] = 0;  
        curcount_--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty())
            return -1;
        return parr_[beginindex_];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
    if (isEmpty())
            return -1;
        return parr_[(endindex_ - 1 + maxcount_) % maxcount_];
        //return parr_[endindex_];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return curcount_ == 0 ? true : false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return curcount_ == maxcount_ ? true : false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */