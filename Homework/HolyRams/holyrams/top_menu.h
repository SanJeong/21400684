#pragma once

int top_menu()
{
    int select;
    std::cout << "------ Holy Rams Management System ------" << std::endl;
    std::cout << "1. Manage Members" << std::endl;
    std::cout << "2. Record Transaction" << std::endl;
    std::cout << "3. Report" << std::endl;
    std::cout << "99. Exit" << std::endl;
    std::cin >> select;
    
    return select;
}