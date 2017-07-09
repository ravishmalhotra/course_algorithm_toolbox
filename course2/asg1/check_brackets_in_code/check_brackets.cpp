#include <iostream>
#include <stack>
#include <string>

struct Bracket
{
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c)
    {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main()
{

    std::string text;
    getline(std::cin, text);

    std::stack <Bracket> opening_brackets_stack;
    for (unsigned int position = 0; position < text.length(); ++position)
    {
        char next = text[position];


        if (next == '(' || next == '[' || next == '{')
        {
            // Process opening bracket, write your code here
            Bracket b_open(next, position);//Constructing a new struct that has the current position and bracket
            opening_brackets_stack.push(b_open);//Pushing it on the stack
        }

        if (next == ')' || next == ']' || next == '}')
        {
            // Process closing bracket, write your code here


            if (opening_brackets_stack.empty())
            {

                std::cout<<position+1;
                return 0;
            }

            else
            {
                Bracket b_close(opening_brackets_stack.top());//Initialize a Bracket variable which is initialized to top of the stack

                if (b_close.Matchc(next)==true)
                    opening_brackets_stack.pop();

                else
                {

                    std::cout<<position+1;
                    return 0;
                }

            }

        }



    }

    if (opening_brackets_stack.empty())
        std::cout<<"Success";

    else
    {
        Bracket b_remaining(opening_brackets_stack.top());
        std::cout<<b_remaining.position+1;
    }


    // Printing answer, write your code here

    return 0;
}
