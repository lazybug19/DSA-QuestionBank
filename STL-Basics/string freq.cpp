#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char name[100];
    int max = 1;
    char mx;
    cout << "Type string: ";
    gets(name);
    for(int i = 0; name[i] != '\0'; i++)
    {
        int p = 1;
        if(name[i] != ' ' || name[i] != '\t')
        {
            for(int j = i + 1; name[j] != '\0'; j++)
            {
                if(name[i] == name[j])
                {
                    p++;
                    name[j] = ' ';
                }
            }
            if (name[i] != ' ')
                {
                    cout << name[i] << " occurs " << p << " times " << endl;
                    if (max < p)
                    {
                        max = p;
                        mx = name[i];
                    }
                }
        }
    }
    cout << mx << " occurs maximum : " << max << " times";
    
    return 0;
}

//structure

#include <iostream>
#include <string.h>
using namespace std;

struct freq{
    char l;
    int f;
}

int main()
{
    char name[100];
    freq line[100];
    int k = 0, max = 1;
    cout << "Type string: ";
    gets(name);
    for(int i = 0; name[i] != '\0'; i++)
    {
        int p = 1;
        if(name[i] != ' ' || name[i] != '\t')
        {
            for(int j = i + 1; name[j] != '\0'; j++)
            {
                if(name[i] == name[j])
                {
                    p++;
                    name[j] = ' ';
                }
            }
            if (name[i] != ' ')
                {
                    line[k].l = name[i];
                    line[k].f = p;
                    if (max < line[k].f)
                    {
                        max = line[k].f;
                        mx = name[i];
                    }
                }
        }
        k++;
    }
    cout << mx << " occurs maximum : " << max << " times";
    
    return 0;
}










