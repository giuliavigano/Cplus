/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvigano <gvigano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:52:59 by gvigano           #+#    #+#             */
/*   Updated: 2025/07/26 11:53:00 by gvigano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main(void) {

    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f); 
    Point c(2.0f, 3.0f);
    
    std::cout << "\nTriangle: A(0,0) - B(4,0) - C(2,3)" << std::endl;
    
    std::cout << "\n--- TEST 1: Points INSIDE the triangle ---" << std::endl;
    Point insideA(2.0f, 1.0f);
    Point insideB(1.0f, 0.5f);
    Point insideC(2.5f, 1.5f);
    std::cout << "Point (2,1): " << (bsp(a, b, c, insideA) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (1,0.5): " << (bsp(a, b, c, insideB) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (2.5,1.5): " << (bsp(a, b, c, insideC) ? "INSIDE" : "OUTSIDE") << std::endl;

    std::cout << "\nTEST 2: Points on VERTICES:" << std::endl;
    std::cout << "Vertex A(0,0): " << (bsp(a, b, c, a) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Vertex B(4,0): " << (bsp(a, b, c, b) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Vertex C(2,3): " << (bsp(a, b, c, c) ? "INSIDE" : "OUTSIDE") << std::endl;
    
    std::cout << "\nTEST 3: Points on EDGES; " << std::endl;
    Point onAB(2.0f, 0.0f);
    Point onBC(3.0f, 1.5f);
    Point onCA(1.0f, 1.5f);
    std::cout << "On edge AB (2,0): " << (bsp(a, b, c, onAB) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "On edge BC (3,1.5): " << (bsp(a, b, c, onBC) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "On edge CA (1,1.5): " << (bsp(a, b, c, onCA) ? "INSIDE" : "OUTSIDE") << std::endl;
    
    std::cout << "\nTEST 4: Points OUTSIDE the triangle: " << std::endl;
    Point outside1(-1.0f, -1.0f);
    Point outside2(5.0f, 0.0f);
    Point outside3(2.0f, 4.0f);
    Point outside4(0.0f, 2.0f);
    std::cout << "Point (-1,-1): " << (bsp(a, b, c, outside1) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (5,0): " << (bsp(a, b, c, outside2) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (2,4): " << (bsp(a, b, c, outside3) ? "INSIDE" : "OUTSIDE") << std::endl;
    std::cout << "Point (0,2): " << (bsp(a, b, c, outside4) ? "INSIDE" : "OUTSIDE") << std::endl;
    
    std::cout << "\nTEST 5: DEGENERATE triangle (aligned points): " << std::endl;
    Point d(0.0f, 0.0f);
    Point e(2.0f, 0.0f);
    Point f(4.0f, 0.0f);
    Point test(1.0f, 1.0f);
    std::cout << "Degenerate triangle with point (1,1): " << (bsp(d, e, f, test) ? "INSIDE" : "OUTSIDE") << std::endl;
    
    std::cout << "\nTEST 6: Triangle with NEGATIVE coordinates:" << std::endl;
    Point g(-2.0f, -1.0f);
    Point h(0.0f, -1.0f);
    Point i(-1.0f, 1.0f);
    Point testNeg(-1.0f, 0.0f);
    std::cout << "Negative triangle with point (-1,0): " << (bsp(g, h, i, testNeg) ? "INSIDE" : "OUTSIDE") << std::endl;
    return 0;
}