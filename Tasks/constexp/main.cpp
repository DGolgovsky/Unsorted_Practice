/*
	constexpr int foo(int a, int b) { return a+b; }
	static constexpr int n = foo(1, 2);
	int bar() { return n; }
*/

struct PodFrac {
    int num;
    int den;
};
 
constexpr int mcd(int a, int b) {
    return (b==0)? a : mcd(b, a%b);
}
 
constexpr PodFrac simpl(const PodFrac &f) {
    return PodFrac{f.num / mcd(f.num, f.den), f.den / mcd(f.num, f.den)};
}
 
constexpr PodFrac sum(const PodFrac &a, const PodFrac &b) {
    return simpl(PodFrac{a.num*b.den + b.num*a.den, a.den*b.den});
}
 
constexpr int fact(int n) {
    return (n==0)? 1 : n*fact(n-1);
}
 
constexpr PodFrac e(int n) {
    return (n==0)? PodFrac{1, 1} :
                   sum(PodFrac{1, fact(n)}, e(n-1));
}
 
constexpr float e_num = 1.0 * e(8).num / e(8).den;
 
float get_e() {
    return e_num;
}
