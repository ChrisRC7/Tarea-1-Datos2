class Node {
    private: int data;
    Node* next; 
    Node* previous;

    public: Node(int data){
        this->next= nullptr;
        this->previous= nullptr;
        this->data= data;
    };

    public: int getData() {
        return this->data;
    }

    public: void setData(int data) {
        this->data= data;
    }

    public: Node* getNext() {
        return this->next;
    }

    public: Node* getPrevious() {
        return this->previous;
    }

    public: void setNext(Node* node) {
        this->next= node;
    }

    public: void setPrevious(Node* node){
        this->previous= node;
    }
};
