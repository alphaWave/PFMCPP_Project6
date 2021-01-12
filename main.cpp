/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>
struct T
{
    T(unsigned int v, const char* w) : value(v), word(w) {}   //1
    unsigned int value; //2
    std::string word; //3
};

struct Tcompare                                //4
{
    T* compare(T& a, T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;
    }
};

struct U
{
    float value1 { 0 }, value2 { 0 };
    float calculateSomething(float& updatedVal)      //12
    {
        std::cout << "U's value1 value: " << this->value1 << std::endl;
        this->value1 = updatedVal;
        std::cout << "U's value1 updated value: " << this->value1 << std::endl;
        
        while( std::abs(this->value2 - this->value1) > 0.001f )
        {
            this->value2 += (this->value1 - this->value2) / 2;
        }
        std::cout << "U's value2 updated value: " << this->value2 << std::endl;
        return this->value2 * this->value1;    
    }
};

struct Uextended
{
    static float calculateSomething(U& that, float& updatedVal)        //10
    {
        std::cout << "U's value1 value: " << that.value1 << std::endl;
        that.value1 = updatedVal;
        std::cout << "U's value1 updated value: " << that.value1 << std::endl;
        
        while( std::abs(that.value2 - that.value1) > 0.001f )
        {
            /*
            write something that makes the distance between that->value2 and that->value1 get smaller
            */
            that.value2 += (that.value1 - that.value2) / 2;
        }
        std::cout << "U's value2 updated value: " << that.value2 << std::endl;
        return that.value2 * that.value1;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(20, "First word");                                             //6
    T t2(15, "Second word");                                             //6
    
    Tcompare f;                                            //7
    auto* smaller = f.compare(t1, t2);                              //8
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->value << std::endl; //9
    }
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << Uextended::calculateSomething(u1, updatedValue) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.calculateSomething(updatedValue) << std::endl;
}
