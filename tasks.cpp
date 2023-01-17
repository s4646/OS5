#include "tasks.hpp"

void* print(void* vp)
{
    std::string *sp = static_cast<std::string*>(vp);
    std::cout << "palindrome: " +(*sp) + "\n";
    return vp;
}

void* removeSpecialChars(void *vp)
{
    std::string *sp = static_cast<std::string*>(vp);
    std::cout << "original: " +(*sp) + "\n";
    
    std::string str;
    bool ok;
    for (auto element : *sp)
    {
        ok = false;
        if (element == 32)                   // space
            ok = true;
        
        if (element >= 48 && element <= 57)  // number
            ok = true;
        
        if (element >= 65 && element <= 90)  // uppercase
            ok = true;
        
        if (element >= 97 && element <= 122) // lowercase
            ok = true;
        
        if (ok)
            str += element;
    }

    *sp = str;
    vp = static_cast<void*>(sp);
    return vp;
}

void* bigCharsOnly(void *vp)
{
    std::string *sp = static_cast<std::string*>(vp);
    
    std::string str;
    for (auto element : *sp)
    {
        if (element >= 48 && element <= 57)  // number
            str += " ";
            
        else if (element >= 97 && element <= 122) // lowercase
            str += (element-32);
        
        else                                 // space or uppercase
            str += element;
    }

    *sp = str;
    vp = static_cast<void*>(sp);
    return vp;
}

void* isPalindrome(void *vp)
{
    std::string *sp = static_cast<std::string*>(vp);
    int length = (*sp).size();
    
    bool ok = true;
    for(int i = 0; i < length ; i++)
    {
        if((*sp)[i] != (*sp)[length-i-1])
        {
            ok = false;
            break;
        }
    }
    if (ok)
    {
        *sp = "YES";
    }
    else
    {
        *sp = "NO";
    }

    return static_cast<void*>(sp);
}