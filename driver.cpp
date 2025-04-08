#include "Base_Array.h"
#include "Base_Array.cpp"
#include "Array.h"
#include "Array.cpp"
#include "Fixed_Array.h"
#include "Fixed_Array.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include "Queue.h"
#include "Queue.cpp"
#include "Expr_Parser.cpp"
#include "Expr_Evaluator.cpp"
#include "Expr_Evaluator.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        // TODO Add code here to test your Array class.
        char ch = 'A';
        char value = 'B';

        std::cout << "----------------------------------------------------------" << std::endl;
        std::cout << "                         VOID                             " << std::endl;
        std::cout << "----------------------------------------------------------" << std::endl;

        std::cout << "Checking Base Array with void parameters:" << std::endl;
        Base_Array<char> arr31;
        std::cout << "" << std::endl;

        std::cout << "Checking Array with void parameters and this should also call default Base Array:" << std::endl;
        Array<char> arr1;
        std::cout << "" << std::endl;

        std::cout << "Checking Fixed Array with void parameters and fixed length of 5 and this should also call default Base Array:" << std::endl;
        Fixed_Array<char, 5> arr10;
        std::cout << "" << std::endl;

        std::cout << "Checking Stack with void parameters and this should also call default Base Array and Array:" << std::endl;
        Stack<char> arr21;
        std::cout << "" << std::endl;

        std::cout << "Checking Queue with void parameters and this should also call default Base Array and Array:" << std::endl;
        Queue<char> arr41;
        std::cout << "" << std::endl;

        std::cout << "----------------------------------------------------------" << std::endl;
        std::cout << "                         SIZE                             " << std::endl;
        std::cout << "----------------------------------------------------------" << std::endl;

        std::cout << "Checking Base Array with size parameters:" << std::endl;
        Base_Array<char> arr32(8);
        std::cout << "" << std::endl;

        std::cout << "Checking Array with size parameters and this should also call default Base Array:" << std::endl;
        Array<char> arr2(8);
        std::cout << "" << std::endl;

        std::cout << "Fixed Array has size parameter fixed to 5 here." << std::endl;

        std::cout << "----------------------------------------------------------" << std::endl;
        std::cout << "                         FILL                             " << std::endl;
        std::cout << "----------------------------------------------------------" << std::endl;

        std::cout << "Checking Base Array with size and fill parameters:" << std::endl;
        Base_Array<char> arr33(5, 'A');
        std::cout << "" << std::endl;

        std::cout << "Checking Array with size and fill parameters and this should also call default Base Array:" << std::endl;
        Array<char> arr3(8, 'A');
        std::cout << "" << std::endl;

        std::cout << "Checking Fixed Array of size 5 with fill parameters and this should also call default Base Array:" << std::endl;
        Fixed_Array<char, 5> arr11('A');

        std::cout << "----------------------------------------------------------" << std::endl;
        std::cout << "                         STACK                            " << std::endl;
        std::cout << "----------------------------------------------------------" << std::endl;
        Stack<int> st;
        arr21.push('a');
        arr21.push('c');
        arr21.push('e');
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        std::cout << "Pushed 2, 3, 4, 5 on the stack.." << std::endl;
        std::cout << "Topmost element on the stack is " << st.top() << " and size of the stack is " << st.size() << std::endl;
        st.pop();
        std::cout << "Popped the topmost element.." << std::endl;
        // std::cout << "Topmost element on the stack after popping is " << st.top() << " and size of the stack is " << st.size() << std::endl;

        std::cout << "----------------------------------------------------------" << std::endl;
        std::cout << "                         QUEUE                            " << std::endl;
        std::cout << "----------------------------------------------------------" << std::endl;
        Queue<int> qu;
        qu.enqueue(9);
        qu.enqueue(8);
        qu.enqueue(7);
        qu.enqueue(6);
        arr41.enqueue('W');
        arr41.enqueue('H');
        arr41.enqueue('O');
        std::cout << "Added 9, 8, 7, 6 on the queue.." << std::endl;
        std::cout << "Size of the queue is " << qu.size() << std::endl;
        qu.dequeue();
        std::cout << "Removed the first element from the queue.." << std::endl;
        std::cout << "After removing, size of the queue is " << qu.size() << std::endl;

        std::cout << "----------------------------------------------------------" << std::endl;
        std::cout << "                         COPY                             " << std::endl;
        std::cout << "----------------------------------------------------------" << std::endl;

        std::cout << "Copying Base Array to a New Base Array" << std::endl;
        Base_Array<char> arr34(arr33);
        std::cout << "" << std::endl;

        std::cout << "Copying Array to a New Array" << std::endl;
        Array<char> arr4(arr3);
        std::cout << "" << std::endl;

        std::cout << "Copying Fixed Array to a New Fixed Array" << std::endl;
        Fixed_Array<char, 5> arr12(arr11);
        std::cout << "" << std::endl;

        std::cout << "Copying Stack to a New Stack" << std::endl;
        Stack<char> arr22(arr21);
        std::cout << "" << std::endl;

        std::cout << "Copying Queue to a New Queue" << std::endl;
        Queue<char> arr42(arr41);
        std::cout << "" << std::endl;

        std::cout << "----------------------------------------------------------" << std::endl;
        std::cout << "                     MISCELLANEOUS                        " << std::endl;
        std::cout << "----------------------------------------------------------" << std::endl;

        arr2.set(3, value);
        cout << "Set new value at index 3 as " << arr2[3] << endl;
        arr3.resize(5);
        cout << "Resized arr3 from 8 to 5." << endl;
        if (arr3.max_size() <= 5)
        {
            cout << "arr3 was resized!" << endl;
        }
        else
        {
            cout << "arr3 was not resized." << endl;
        }

        int pos1 = arr3.find(ch);
        cout << "At pos1, i.e. " << pos1 << " value is " << arr3[pos1] << endl;
        int pos2 = arr3.find(ch, 1);
        cout << "At pos2 after index 1, i.e. " << pos2 << " value is " << arr3[pos1] << endl;

        if (arr3 == arr4)
        {
            cout << "Arrays are equal, even after we resized arr3 and changed character at certain index" << endl;
        }

        if (arr3 != arr4)
        {
            cout << "Arrays are not equal because they are not meant to be equal after what happened to them up there. Phew!" << endl;
        }
        arr2.fill('c');
        std::cout << "" << std::endl;

        std::cout << "----------------------------------------------------------" << std::endl;
        std::cout << "                        CALCULATOR                        " << std::endl;
        std::cout << "----------------------------------------------------------" << std::endl;
        string expression;
        while (true)
        {
            std::cout << "Enter expression (or QUIT to exit): " << std::endl;
            std::getline(std::cin, expression);

            if (expression == "QUIT")
            {
                break;
            }

            std::cout << "You entered: " << expression << std::endl;
            std::cout << "Creating postfix commands from the infix tokens converted to postfix tokens.." << std::endl;
            std::vector<Expr_Node> infix_tokens = tokenize_expression(expression);
            std::vector<Expr_Node> postfix_tokens = infix_to_postfix(infix_tokens);
            std::vector<Expr_Command *> commands = build_postfix_commands(postfix_tokens);

            int result = 0;
            bool success = evaluate_postfix_commands(commands, result);

            // Cleaning cmd objects
            for (Expr_Command *cmd : commands)
            {
                delete cmd;
            }
            commands.clear();

            if (success)
            {
                std::cout << result << std::endl;
            }
            else
            {
                std::cout << "ERROR" << std::endl;
            }
        }

        std::cout << "Exiting calculator." << std::endl;
    }
    catch (const Stack<int>::empty_exception &e)
    {
        std::cerr << "Caught empty_exception: " << e.what() << std::endl;
    }

    return 0;
}