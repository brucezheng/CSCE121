/*
	Bruce Zheng
	9/14/12
	Solution for Tokenized Calculator from Ch 6
	Uses tokens, a token stream, and a basic grammar to handle basic arithmetic
	statements while following order of operations; uses Strouststrup ch.6 code
	as starting point
*/

/*
	The grammar used is:
	Expression:
		Term
		Expression + Term
		Expression - Term
	Term:
		Exponential
		Term * Exponential
		Term / Exponential
	Exponential:
		Primary
		Primary ^ Exponential
	Primary:
		Number
		(Expression)
	Number:
		Floating-Point-Literal
*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token {
public:
    char kind;
    double value; 
    Token(char ch)
        :kind(ch), value(0) { }    
    Token(char ch, double val)
        :kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t; 
    full = true; 
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {
        // remove token from buffer
        full = false;
        return buffer;
    } 

    char ch;
    cin >> ch;

    switch (ch) {
    case ';':    // for "print"
    case 'q':    // for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/': case '^': case '!':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
        {    
            cin.putback(ch);         // put digit back into the input stream
            double val;
            cin >> val;              // read a floating-point number
			return Token('#',val);   // let '#' represent "a number"
        }
    default:
        error("Bad token");
    }
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {    
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
	case '#':            // we use '#' to represent a number
        return t.value;  
    default:
        error("primary expected");
    }
}

//------------------------------------------------------------------------------

// deal with exponentials
double exponential()
{
	double base = primary();
    Token t = ts.get();      

    while(true) {
		double product = 1; int power = 0;
        switch (t.kind) {
        case '^':
			//Calls exponential; exponents are calculated from right to left
			power = exponential();
			if (power < 0) error("negative exponent");
			for(int i = 0; i < power; ++i) product *= base;
			base = product;
            t = ts.get();
			break;
        default: 
            ts.putback(t);
            return base;
        }
    }
}

// deal with *, /, and %
double term()
{
    double left = exponential();
    Token t = ts.get();      

    while(true) {
        switch (t.kind) {
        case '*':
            left *= exponential();
            t = ts.get();
			break;
        case '/':
            {    
                double d = exponential();
                if (d == 0) error("divide by zero");
                left /= d; 
                t = ts.get();
                break;
            }
        default: 
            ts.putback(t);     
            return left;
        }
    }
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term(); 
    Token t = ts.get(); 

    while(true) {    
        switch(t.kind) {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left += term();
            t = ts.get();
            break;
        default: 
            ts.putback(t);
            return left; 
        }
    }
}

//------------------------------------------------------------------------------

int main()
try
{
	double val = 0;
    while (cin) {
        Token t = ts.get();

        if (t.kind == 'q') break; 
        if (t.kind == ';')       
            cout << "=" << val << '\n';
        else
            ts.putback(t);
        val = expression();
    }
	keep_window_open();
}
catch (exception& e) {
    cerr << "error: " << e.what() << '\n'; 
	keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Oops: unknown exception!\n"; 
	keep_window_open();
    return 2;
}

//------------------------------------------------------------------------------