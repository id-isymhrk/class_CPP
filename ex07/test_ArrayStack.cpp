// test_ArrayStack.cpp
#include "ArrayStack.h"
#include <vector>

// using namespace std;

void result(ArrayStack stack);

int main(void)
{
     // Create an instance of ArrayStack named stack1
     //   using the default constructor
     // Push several items in this stack.
     ArrayStack stack1;
     vector<string> test1 = {"University", "of", "Aizu"};

     cout << "---stack1---" << endl;
     for (int i = 0; i < test1.size(); i++)
     {
          cout << test1[i] << endl;
          stack1.push(test1[i]);
     }

     cout << endl;
     cout << "-----------" << endl;
     cout << "stack1 size:" << stack1.size() << endl;
     cout << "-----------" << endl;
     cout << endl;

     cout << endl;
     cout << endl;
     cout << endl;
     // Create another instance of ArrayStack named stack2
     //   using the other constructor, specify an original size of 5
     // Push several items in this stack.
     const int SIZE_S2 = 5;

     ArrayStack stack2(SIZE_S2);
     string test2[SIZE_S2] = {"1:Aizu", "2:Hukushima", "3:Tohoku", "4:Japan", "5:Earth"};

     cout << "---stack2---" << endl;
     for (int i = 0; i < SIZE_S2; i++)
     {
          cout << test2[i] << endl;
          stack2.push(test2[i]);
     }

     cout << endl;
     cout << "-----------" << endl;
     cout << "stack2 size:" << stack2.size() << endl;
     cout << "-----------" << endl;
     cout << endl;

     cout << endl
          << endl
          << endl;

     cout << "---stack3---" << endl;
     cout << "stack3 = move(stack1)" << endl;
     ArrayStack stack3 = move(stack1);
     // result(stack3);
     cout << endl
          << endl
          << endl;

     cout << "---stack4---" << endl;
     cout << "stack4 = move(stack2)" << endl;
     ArrayStack stack4 = move(stack2);
     // result(stack4);
     cout << endl
          << endl
          << endl;

     // Assignment
     ArrayStack stack5;
     cout << "---stack5---" << endl;
     cout << "stack5 = stack1" << endl;
     stack5 = stack1;
     // result(stack5);
     cout << endl
          << endl
          << endl;

     ArrayStack stack6;
     cout << "---stack6---" << endl;
     stack6.push("only one.");
     cout << "pushed word \"only one\" to stack6." << endl;
     cout << endl;
     cout << "-----------" << endl;
     cout << "stack6 size:" << stack6.size() << endl;
     cout << "-----------" << endl;
     cout << endl;
     cout << endl;

     cout << "---stack1---" << endl;
     stack1.show_items();
     cout << "size:" << stack1.size() << endl;
     cout << endl;
     // result(stack1);
     cout << "---stack2---" << endl;
     stack2.show_items();
     cout << "size:" << stack2.size() << endl;
     cout << endl;
     // result(stack2);
     cout << "---stack3---" << endl;
     stack3.show_items();
     cout << "size:" << stack3.size() << endl;
     cout << endl;
     // result(stack3);
     cout << "---stack4---" << endl;
     stack4.show_items();
     cout << "size:" << stack4.size() << endl;
     cout << endl;
     // result(stack4);
     cout << "---stack5---" << endl;
     stack5.show_items();
     cout << "size:" << stack5.size() << endl;
     cout << endl;
     cout << "---stack6---" << endl;
     stack6.show_items();
     cout << "size:" << stack6.size() << endl;
     cout << endl;

     // copy & test
     vector<ArrayStack> stack_test = {stack1, stack2, stack3, stack4, stack5, stack6};

     cout << endl;

     for (int i = 0; i < stack_test.size(); i++)
     {
          try
          {
               cout << "---stack" << i + 1 << ".top()---" << endl;
               cout << stack_test[i].top() << endl;
               cout << "Can you look me?" << endl;
          }
          catch (const std::exception &e)
          {
               // std::cerr << "Stack is empty. Error!" << std::endl;
               std::cerr << "Error!" << std::endl;
               std::cout << e.what() << std::endl;
          }

          cout << endl;
     }
     cout << endl
          << endl
          << endl;

     for (int i = 0; i < stack_test.size(); i++)
     {
          try
          {
               cout << "---stack" << i + 1 << ".pop()---" << endl;
               stack_test[i].pop();
               cout << "pop is success!" << endl;
               cout << endl;
               cout << "stack" << i + 1 << ".top() is "
                    << "\"" << stack_test[i].top() << "\"" << endl;
               cout << "Can you look me?" << endl;
          }
          catch (const std::exception &e)
          {
               // std::cerr << "Stack is empty. Error!" << std::endl;
               std::cerr << "Error!" << std::endl;
               std::cout << e.what() << std::endl;
          }

          cout << endl;
     }

     return 0;
}

void result(ArrayStack stack)
{
     // cout << "---stack pop---" << endl;
     for (int i = 0; !stack.empty(); i++)
     {
          cout << stack.top() << endl;
          stack.pop();
     }
}