/*
https://www2.cs.duke.edu/courses/spring00/cps100/assign/trees/diameter.html

The diameter of a tree T is the largest of the following quantities:

the diameter of T's left subtree
the diameter of T's right subtree
the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)

https://stackoverflow.com/questions/2446465/finding-two-most-distant-elements-in-a-binary-tree
What you are looking for can be named graph diameter. In order to get it you'll need to calculate the path from any vertex to any other and then go through all of them and find the largest one.
That can be achieved using Dijkstra's algorithm
*/

int diameter(tree * t)
{ 
	if (t == 0) return 0; 
	int lheight = height(tree->left); 
	int rheight = height(tree->right);
	int ldiameter = diameter(tree->left); 
	int rdiameter = diameter(tree->right); 
	return max(lheight + rheight + 1, max(ldiameter,rdiameter));
} 

int height(tree * t)
{
	if (t == 0)
		return 0;
	return 1 + max(height(t->left),height(t->right));
}
