//
// Created by fail on 9/29/21.
//

#ifndef LAB01_PART2_EXPRESSION_PARSER_H
#define LAB01_PART2_EXPRESSION_PARSER_H

#include <string>
#include <vector>
#include <stack>
#include <stdexcept>
#include <cmath>

enum expression_type { OPERATOR, NUMBER, VARIABLE, NIL};

struct token {
    expression_type type = NIL;
    uint64_t val = 0;
};

static int precedence(char ch) {
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    if(ch == '^') return 3;

    return -1;
}

static void token_insert(std::vector<token>& output, char p) {
    if(std::isalpha(p)) {
        output.push_back({VARIABLE, static_cast<uint64_t>(p)});
    } else if(std::isdigit(p)) {
        output.push_back({NUMBER, static_cast<uint64_t>(p - '0')});
    } else {
        output.push_back({OPERATOR, static_cast<uint64_t>(p)});
    }
}
#include <iostream>
class expression_parser {
public:
    static std::vector<token> infix_to_rpn(const std::string& expr) {
        std::stack<char> st;
        std::vector<token> output;

        for(std::size_t i = 0; i < expr.size(); ++i) {
            char c = expr[i];
            if(std::isspace(c)) continue;

            if(std::isalpha(c)) {
                output.push_back({VARIABLE, static_cast<uint64_t>(c)});
            } else if(std::isdigit(c)) {
                uint64_t num = 0;

                do {
                    num *= 10;
                    num += expr[i] - '0';
                    ++i;
                } while(i < expr.size() && std::isdigit(expr[i]));
                if(i < expr.size() && !std::isdigit(expr[i])) --i;

                output.push_back({NUMBER, static_cast<uint64_t>(num)});
            } else if(c == '(') {
                st.push(c);
            } else if(c == ')') {
                while(!st.empty() && st.top() != '(') {
                    char p = st.top();
                    st.pop();
                    token_insert(output, p);
                }
                st.pop();
            } else {
                while(!st.empty() && precedence(c) <= precedence(st.top())) {
                    char p = st.top();
                    st.pop();
                    token_insert(output, p);
                }
                st.push(c);
            }
        }

        while(!st.empty()) {
            if(st.top() == '(') throw std::invalid_argument("Input doesn't have balanced brackets");

            char p = st.top();
            st.pop();
            token_insert(output, p);
        }

        return output;
    }

    static double calculate(double x, const std::vector<token>& rpn) {
        if(rpn.empty()) return 0;

        if(rpn.size() == 1) {
            if(rpn[0].type == VARIABLE) return rpn[0].val;
            throw std::logic_error("Invalid RPN");
        }

        std::stack<token> st;

        std::stack<double> values;
        for(const auto& t : rpn) {
            if(t.type == OPERATOR) {
                switch (t.val) {
                    case '+':
                    {
                        if(values.size() < 2) throw std::logic_error("Invalid RPN");
                        double r1 = values.top();
                        values.pop();
                        double r2 = values.top();
                        values.pop();
                        values.push(r1 + r2);
                        break;
                    }
                    case '-':
                    {
                        if(values.size() < 2) throw std::logic_error("Invalid RPN");
                        double r1 = values.top();
                        values.pop();
                        double r2 = values.top();
                        values.pop();
                        values.push(r2 - r1);
                        break;
                    }
                    case '*':
                    {
                        if(values.size() < 2) throw std::logic_error("Invalid RPN");
                        double r1 = values.top();
                        values.pop();
                        double r2 = values.top();
                        values.pop();
                        values.push(r1 * r2);
                        break;
                    }
                    case '/':
                    {
                        if(values.size() < 2) throw std::logic_error("Invalid RPN");
                        double r1 = values.top();
                        values.pop();
                        double r2 = values.top();
                        values.pop();
                        values.push(r2 / r1);
                        break;
                    }
                    case '^':
                    {
                        if(values.size() < 2) throw std::logic_error("Invalid RPN");
                        double r1 = values.top();
                        values.pop();
                        double r2 = values.top();
                        values.pop();
                        values.push(std::pow(r2, r1));
                        break;
                    }
                    default:
                    {
                        throw std::logic_error("Unexpected operator " + std::to_string(t.val));
                    }
                }
            } else if(t.type == NUMBER) {
                values.push(t.val);
            } else if(t.type == VARIABLE) {
                if(t.val != 'x') throw std::logic_error("Unknown variable " + std::to_string(t.val));
                values.push(x);
            } else {
                throw std::logic_error("Unexpected token " + std::to_string(t.type));
            }
        }

        return values.top();
    }
};


#endif //LAB01_PART2_EXPRESSION_PARSER_H
