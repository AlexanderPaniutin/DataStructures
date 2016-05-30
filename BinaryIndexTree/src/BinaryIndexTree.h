#include <vector>

using namespace std;

class BinaryIndexTree {
    public:
        void print();
        int getSum(unsigned int ndxStart, unsigned int ndxEnd);
        void addItem();
        void updateItem(unsigned int ndx, int value);

    private:
        vector<int> items;
};
