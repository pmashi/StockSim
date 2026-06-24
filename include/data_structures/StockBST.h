#pragma once 

#include <string> 
#include <vector> 
using std::string; 
using std::vector; 

namespace stocksim {
    struct BSTNode {
        string ticker; 
        double key; 
        int year; 
        BSTNode* left; 
        BSTNode* right; 
    
        BSTNode(const string& t, double k, int y) 
                : ticker(t), key(k), year(y), left(nullptr), right(nullptr) {}
    };

    class StockBST {
    private: 
        BSTNode* root; 

        BSTNode* insertHelper(BSTNode* node, const string& ticker, double key, int year); 
        BSTNode* searchHelper(BSTNode* node, double key) const; 
        void rangeSearchHelper(BSTNode* node, double low, double high, vector<BSTNode*>& results) const;
        
        void inorderHelper(BSTNode* node)   const; 
        void preorderHelper(BSTNode* node)  const; 
        void postorderHelper(BSTNode* node) const; 
        int heightHelper(BSTNode* node)     const; 
        
        void clearHelper(BSTNode* node); 
    public: 
        StockBST(); 
        ~StockBST(); 

        void insert(const string& ticker, double key, int year); 
        BSTNode* search(double key) const; 
        void rangeSearch(double low, double high, vector<BSTNode*>& results) const; 

        void inorder() const; 
        void preorder() const; 
        void postorder() const; 
        
        int getHeight() const; 
        void clear(); 
        bool isEmpty() const; 
    };
}