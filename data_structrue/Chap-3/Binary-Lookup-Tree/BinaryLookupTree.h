struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(int x,SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree InSert_1(int x,SearchTree T);
SearchTree InSert_2(int x, SearchTree T);
SearchTree Delete(int x,SearchTree T);
void PtrTree(SearchTree T);


struct TreeNode
{
    int x;
    SearchTree left;
    SearchTree right;
};
