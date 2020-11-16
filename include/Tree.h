#ifndef TREE_H_
#define TREE_H_

#include <vector>

class Session;

class Tree{
public:
    Tree(int rootLabel);
    virtual ~Tree();
    Tree(const Tree &tree);
    Tree & operator=(const Tree &tree);
    Tree(Tree &&tree);
    Tree & operator=( Tree &&tree);
    void clear();
    std::vector<Tree*> copyChildren() const;
    void addChild(const Tree& child);
    void addChild(Tree* child);
    int getNode() const;
    std::vector<Tree*> getChildren();
    virtual Tree* clone() const = 0;
    static Tree* createTree(const Session& session, int rootLabel);
    virtual int traceTree()=0;
    void setNode(int _node);

protected:
    int node;
    std::vector<Tree*> children;
};

class CycleTree: public Tree{
public:
    CycleTree(int rootLabel, int currCycle);
    virtual int traceTree();
    virtual Tree* clone() const;
private:
    int currCycle;
};

class MaxRankTree: public Tree{
public:
    MaxRankTree(int rootLabel);
    virtual int traceTree();
    virtual Tree* clone() const;
};

class RootTree: public Tree{
public:
    RootTree(int rootLabel);
    virtual int traceTree();
    virtual Tree* clone() const;
};

#endif
