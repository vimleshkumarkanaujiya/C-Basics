class ArrayList {
private:
    int* array;
    int size;
    int capacity;

public:
    ArrayList() {
        size = 0;
        capacity = 10;
        array = new int[capacity];
    }

    ~ArrayList() {
        delete[] array;
    }

    void add(int value) {
        if (size == capacity) {
            int* newArray = new int[capacity * 2];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
            capacity *= 2;
        }
        array[size] = value;
        size++;
    }

    int get(int index) {
        if (index >= 0 && index < size) {
            return array[index];
        }
        // Handle out-of-bounds error
        return -1;
    }

    void remove(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                array[i] = array[i + 1];
            }
            size--;
        }
        // Handle out-of-bounds error
    }

    int getSize() {
        return size;
    }
};
