// Demonstrates non-overloadable operators in comments only:
// :: scope resolution, . member access, .* pointer-to-member,
// ?: conditional operator, sizeof size operator.
struct Item { int value; };
int main(){ Item x{1}; Item* p=&x; return p->value; }
