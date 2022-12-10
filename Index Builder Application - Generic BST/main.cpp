#include <fstream>
#include <bits/stdc++.h>
#include "include/BSTFCI.h"

void remove_punctuation(string&);
int main()
{
    ///BST test cases
    /*BSTFCI<int> tree,t,t1,t2,t3;

    tree.add(5);
    tree.add(3);
    tree.add(7);
    tree.add(2);
    tree.add(4);
    tree.add(9);
    tree.add(1);
    tree.add(8);
    tree.add(10);

    t1.add(3);
    t1.add(2);
    t1.add(1);
    t1.add(4);

    t2.add(9);
    t2.add(8);
    t2.add(10);


    t.add(5);
    t.add(3);
    t.add(13);
    t.add(1);
    t.add(4);
    t.add(10);
    t.add(15);

    t3.add(1);
    t3.add(3);
    t3.add(4);
    t3.add(5);
    t3.add(10);
    t3.add(13);
    t3.add(15);

    tree.printRange(3,6);
    tree.printRange(8,15);
    tree.printRange(6,6);
    cout << tree.isSubTree(&tree,&t1) << endl;
    cout << tree.isSubTree(&tree,&t2) << endl;
    cout << tree.isSubTree(&tree,&t) << endl << endl;
    cout << tree.isBalanced() << endl ;
    cout << tree.size() << endl;
    cout << tree.get_height() << endl;
    //tree.flip();
    tree.breadth_print();
    tree.inorder_print();
    tree.preorder_print();
    tree.postorder_print();
    tree.cut(5);
    tree.breadth_print();
    tree.inorder_print();
    tree.preorder_print();
    tree.postorder_print();
    cout << tree.size() << endl;
    tree.breadth_print();
    tree.inorder_print();
    tree.preorder_print();
    tree.postorder_print();*/
    ///Application
    BSTFCI<Word> words;
    Word w;string str;
    ifstream file("text.txt",ios::in);
    for(int i = 1;true;i++)
    {
        getline(file,str);
        if(file.fail())
            break;
        stringstream ss(str);
        while(true)
        {
            ss >> str;
            if(ss.fail())
                break;
            remove_punctuation(str);
            w.clear();
            w.set_word(str);
            w.add_index(i);
            words.add(w);
        }
    }
    words.inorder_print();
    ///simulation to file of words in integer
    /*BSTFCI<int> tr;
    tr.add(10);
    tr.add(20);
    tr.add(5);
    tr.add(21);
    tr.add(17);
    tr.add(7);
    tr.add(3);
    tr.add(19);
    tr.add(16);
    tr.add(18);
    tr.add(12);
    tr.add(13);
    tr.add(11);
    tr.add(14);
    tr.inorder_print();
    tr.breadth_print();*/

    return 0;
}
void remove_punctuation(string& s)
{
    string temp;
    for(unsigned int i = 0;i < s.size();i++)
    {
        if(s[i] != ',' && s[i] != '.')
            temp += s[i];
    }
    s = temp;
}
