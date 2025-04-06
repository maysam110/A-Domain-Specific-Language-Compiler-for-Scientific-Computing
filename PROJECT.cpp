#include <iostream>
using namespace std;
#include <string>

class Compiler {
public:
    static int compileAndExecute(const std::string& code) {
      
        int result = eval(code);
        
        return result;
    }
};

int main() {
    std::string code = "2 + 3 * 4 - 1";

    int result = Compiler::compileAndExecute(code);

    std::cout << "Result: " << result << std::endl;

    return 0;
}




#include <iostream>
#include <string>

// Abstract syntax tree (AST) node
class AstNode {
public:
    virtual double evaluate() const = 0;
};

// Constant value node	
class ConstantNode : public AstNode {
private:
    double value;

public:
    ConstantNode(double val) : value(val) {}

    double evaluate() const override {
        return value;
    }
};

// Addition operation node
class AddNode : public AstNode {
private:
    AstNode* left;
    AstNode* right;

public:
    AddNode(AstNode* l, AstNode* r) : left(l), right(r) {}

    double evaluate() const override {
        return left->evaluate() + right->evaluate();
    }
};

// Subtraction operation node
class SubtractNode : public AstNode {
private:
    AstNode* left;
    AstNode* right;

public:
    SubtractNode(AstNode* l, AstNode* r) : left(l), right(r) {}

    double evaluate() const override {
        return left->evaluate() - right->evaluate();
    }
};

// Multiplication operation node
class MultiplyNode : public AstNode {
private:
    AstNode* left;
    AstNode* right;

public:
    MultiplyNode(AstNode* l, AstNode* r) : left(l), right(r) {}

    double evaluate() const override {
        return left->evaluate() * right->evaluate();
    }
};

// DSL Compiler
class Compiler {
public:
    static AstNode* compileExpression(const std::string& expr) {
        // TODO: Implement the DSL compiler logic here

        // For this example, we will simply create a constant node with a value of 42
        return new ConstantNode(42.0);
    }
};

int main() {
    std::string expression = "2 + 3 * 4 - 1";

    AstNode* ast = Compiler::compileExpression(expression);

    double result = ast->evaluate();

    std::cout << "Result: " << result << std::endl;

    // Clean up the AST
    delete ast;

    return 0;
}
