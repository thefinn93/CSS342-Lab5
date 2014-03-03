/**
 * @author Nicholas Abel, Finn Herzfeld
 * @date 3/02/2014
 * 
 */

/**
 * The main test file for Lab 5.
 * Contains units tests for the following:
 * 
 * NodeData
 * Node
 * ThreadedBST
 * 
 * 
 */

#include <cstdlib>

using namespace std;

/*NodeData Tests*/

/*Testing Constructors*/

NodeData::NodeData():token(""), frequency(0)

/*
 * Test NodeData()
 * Returns a boolean
 * 
 * Create new NodeData() blankData
 * Check that default values are as expected.
 * Use NodeData() getters.
 * token: ""
 * frequency: 0
 * If token and frequency match these values, return True
 */

NodeData::NodeData(char newToken[], int newFrequency = 1)

//Good data tests

/*
 * Test nodeDataTest1(char newToken[])
 * Returns a boolean.
 * 
 * Create new NodeData("Test")
 * 
 * Check that default values are as expected.
 * Use NodeData() getters.                              //Also test getters
 * token: "Test"
 * frequency: 1
 * If token and frequency match these values, return True
 */

/*
 * Test nodeDataBig5(char newToken[], int newFrequency)
 * Returns a boolean.
 * 
 * Create new NodeData("Big", 5)
 * 
 * Check that default values are as expected.
 * Use NodeData() getters.                              //Also test getters
 * token: "Big"
 * frequency: 5
 * If token and frequency match these values, return True
 */

//Bad data tests

/*
 * Not testing bad data, error checking handled by implementation
 */

NodeData::NodeData(const NodeData& nodeDataToCopy)

/*
 * Test nodeDataCopy5(const NodeData& nodeDataToCopy)
 * Returns a boolean.
 * 
 * Create new NodeData(nodeDataBig5) //using previous nodeDataBig5
 * 
 * Check that default values are as expected.
 * Use NodeData() getters.                              //Also test getters
 * token: "Big"
 * frequency: 5
 * If token and frequency match these values, return True
 */

/*Test Assignment*/

NodeData::operator=(const NodeData& rightData)

/*
 * Test nodeDataAssign = nodeDataCopy5
 * Returns a boolean.
 * 
 * Check that default values are as expected.
 * Use NodeData() getters.                              //Also test getters
 * token: "Big"
 * frequency: 5
 * If token and frequency match these values, return True
 */


/*Test Comparison Operators*/

bool NodeData::operator== (const NodeData& rightData)

/*
 * Does nodeDataAssign == nodeDataCopy5
 * Return boolean
 * Expected: True
 * 
 */

bool NodeData::operator< (const NodeData& rightData)

/*
 * is nodeDataTest1 <  nodeDataBig5
 * Return boolean
 * Expected: True
 * 
 * is nodeDataBig5 < nodeDataTest1
 * Return boolean
 * Expected: False
 * 
 */

bool NodeData::operator> (const NodeData& rightData)

/*
 * is nodeDataTest1 >  nodeDataBig5
 * Return boolean
 * Expected: False
 * 
 * is nodeDataBig5 > nodeDataTest1
 * Return boolean
 * Expected: True
 * 
 */

/*Test Methods*/

const int NodeData::getFrequency()

/*
 * Test nodeDataBig5.getFrequency
 * Return int
 * Expected: 5
 * 
 * Test blankData.getFrequency
 * Return int
 * Expected: 0
 */

const char NodeData::getToken()

/*
 * Test nodeDataBig5.getToken
 * Return char[]
 * Expected: "Big"
 * 
 */

bool NodeData::increaseFrequency()

/*
 * Test nodeDataBig5.increaseFrequency
 * Return nodeDataBig using operator <<         //also tests operator <<
 * Expected Big 6
 */

bool NodeData::decreaseFrequency()

/*
 * Test nodeDataBig5.decreaseFrequency
 * Return nodeDataBig using operator <<
 * Expected Big 5
 */

bool NodeData::setToken(char newToken[])

/*
 * Test nodeDataBig5.setToken("Small")
 * Return nodeDataBig using operator <<
 * Expected Small 5
 */

bool NodeData::setFrequency(int newFrequency)

/*
 * Test nodeDataBig5.setFrequency(20)
 * Return nodeDataBig using operator <<
 * Expected Big 20
 */

/*Node Test*/

        /*-----------Comparison Operators-----------*/
  
        Node& operator==(const Node& right) const;

        Node& operator<(const Node& right) const;

        Node& operator>(const Node& right) const;

        Node& operator=(const Node& right);

        Node();
        
        /*
         * Create Node nodeBlankTest
         * Test getData
         * Expected
         */

        Node(NodeData data, Node* left, Node* right);

        Node(const NodeData& nodeToCopy);

        NodeData getData();
        
        /*
         * 
         */
        bool setData(NodeData data);

        bool isRightPtrThread();

        bool isLeftPtrThread();

        void setRightPtrIsThread(bool newvalue);

        void setLefttPtrIsThread(bool newvalue);
        
/*ThreadedBST Test*/
        
    ThreadedBST();
    
    /*
     * Create emptyBST ThreadedBST()
     * 
     * //Test isEmpty()
     * Check that it is empty using isEmpty()
     * Return bool
     * Expected result: True
     * 
     * //Test getSize()
     * Return int
     * Expected result: 1
     * 
     * //Test insert(char)
     * Use insert("One")
     * 
     * //Test getSize()
     * Return int
     * Expected result: 2
     * 
     * //Test insert(char, int)
     * Use insert("Ten", 10)
     * 
     * //Test insertOrIncriment("Five")
     * Use insertOrIncrement("Five")
     * 
     * //Test exists("Five")
     * Return bool
     * Expected result: True
     * 
     * //Test getFrequency("Five")
     * Return int
     * Expected result: 1
     * 
     * Use insertOrIncrement("Five")
     * //Test getFrequency("Five")
     * Return int
     * Expected result: 2
     * 
     * //Test setFrequency("Five", 5)
     * //Test getFrequency("Five")
     * Return int
     * Expected result: 5
     * 
     * //Test getSize()
     * Return int
     * Expected result: 3
     * 
     * //Test remove(
     * 
     */

    /**
     * A constructor that initializes the TBST from a specified root node
     * @param rootNode  The node to use as the root when initalizing the tree.
     */
    ThreadedBST(const NodeData& rootNode);

    /**
     * Initializes a TBST. At this point we have not determined the purpose of
     * this constructor, but it was in the book and we suspect it may come in
     * hand later
     * @param rootNode
     * @param leftTreePtr
     * @param rightTreePtr
     */
    ThreadedBST(const NodeData& rootNode,
                const ThreadedBST* leftTreePtr,
                const ThreadedBST* rightTreePtr);

    /**
     * Creates a deep copy of another TBST.
     * @param treeToCopy    The TBST to copy
     */
    ThreadedBST(const ThreadedBST& treeToCopy);

    /**
     * A destructor. Deletes all the nodes in this tree.
     */
    ~ThreadedBST();

    bool isEmpty();

    bool insert(char[] token, int frequency);

    bool insertOrIncriment(char[] token);

    bool setFrequency(char[] token, int frequency);

    bool remove(char[] token);

    int getFrequency(char[] token);

    bool exists(char[] token);

    int getSize();

    void iterativeInorder(void visit(nodeData&));

    void inorder(void visit(nodeData&), Node* treePtr);

    void preorder(void visit(nodeData&), Node* treePtr);

    void postorder(void visit(nodeData&), Node* treePtr);


private:
    ThreadedBST* rootPtr;

    Node* balancedAdd(Node* subTreePtr, Node* newNodePtr);

    Node* removeHelper(char[] token, Node* root);

    int getHeightHelper(Node* subTreePtr);        

