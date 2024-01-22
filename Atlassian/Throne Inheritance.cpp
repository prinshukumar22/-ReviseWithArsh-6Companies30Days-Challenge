class Node {
    public:
    string val;
    vector<Node*> child;

    Node(string name){
        this->val = name;
    }
};

class ThroneInheritance {
public:
    Node* root = NULL;
    unordered_map<string, Node*> m;
    //unordered_map<string,string> parent;
    //Node* god = new Node("god");
    ThroneInheritance(string kingName) {
        root = new Node(kingName);
        m[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        Node* child = new Node(childName);
        m[parentName]->child.push_back(child);
        m[childName] = child;
    }
    
    void death(string name) { 
        m[name] = NULL;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> ans;
        solve(ans,root);

        return ans;
    }

    void solve(vector<string> &ans, Node* root){
        if(m[root->val]!=NULL)    ans.push_back(root->val);//Checking if current people is dead, if dead then not including that person in our inheritance order
        for(int i=0;i<root->child.size();i++){//Childrens will be present in inheritance order doesn't matter if their parent is dead or alive
            solve(ans, root->child[i]);
        }
        return;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */
