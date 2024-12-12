#include <iostream>
#include "SuffixArray.h"
int main()
{
    SuffixArray t("ACGACTACGATAAC$");//0 => 9
    t.ConstructUsingPrefixDoubling();
    t.Print();
    return 0;
}
