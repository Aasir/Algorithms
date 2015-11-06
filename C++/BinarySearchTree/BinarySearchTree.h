template <typename T>
class treeNode {
public:
    treeNode *left;
    treeNode *right;
    T key;
    treeNode(T key)
        : key(key)
        , left(nullptr)
        , right(nullptr) {
    }
};
