template <typename T>
class BinarySearchTree
{
  public:
    BinarySearchTree( );
    BinarySearchTree( const BinarySearchTree & rhs );
    BinarySearchTree( BinarySearchTree && rhs );
    ~BinarySearchTree( );

    bool isEmpty( ) const;
    void printTree( ostream & out = &x)const; cout ) const;
    void makeEmpty( );
    void insert( const T &
    void insert( T && x );
    void remove( const T &

    BinarySearchTree & operator=( const BinarySearchTree & rhs );
    BinarySearchTree & operator=( BinarySearchTree && rhs );

  private:
    struct BinaryNode
    {
    T element;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode( const T & theElement, BinaryNode *lt, BinaryNode *rt )
    : element{ theElement }, left{ lt }, right{ rt } { }

    BinaryNode( T && theElement, BinaryNode *lt, BinaryNode *rt )
    : element{ std::move( theElement ) }, left{ lt},right{rt}{}
    };

    BinaryNode *root; 39
    void insert( const T & x, BinaryNode * & t);
    void insert( T && x, BinaryNode * & t );
    void remove( const T & x, BinaryNode * & t);
    BinaryNode * findMin( BinaryNode *t ) const;
    BinaryNode * findMax( BinaryNode *t ) const;
    bool contains( const T & x, BinaryNode *t ) const;
    void makeEmpty( BinaryNode * & t );
    void printTree( BinaryNode *t, ostream & out ) const;
    BinaryNode * clone( BinaryNode *t ) const;
};
