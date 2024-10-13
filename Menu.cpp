//
// Created by Chandler Desforges on 5/1/24.
//

#include "Menu.h"
#include "GameLogic.h"

sf::Text Menu::start;
sf::Text Menu::p1score;
sf::Text Menu::p2score;
sf::Font Menu::retro;

namespace fs = std::filesystem;

#if defined(_WIN32)
#include <windows.h>
#elif defined(__unix__) || defined(__APPLE__)
#include <unistd.h>
#endif

namespace fs = std::filesystem;

fs::path getExecutablePath() {
#if defined(_WIN32)
    char path[MAX_PATH] = { 0 };
    GetModuleFileNameA(NULL, path, MAX_PATH);
    return fs::path(path).parent_path();
#elif defined(__linux__)
    char result[PATH_MAX];
    ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
    return fs::path(std::string(result, (count > 0) ? count : 0)).parent_path();
#elif defined(__APPLE__)
    char path[1024];
    uint32_t size = sizeof(path);
    if (_NSGetExecutablePath(path, &size) == 0)
        return fs::path(path).parent_path();
    else
        return fs::path(); // Buffer too small
#else
    return fs::path(); // Unsupported platform
#endif
}


Menu::Menu(sf::Vector2<unsigned int> windowSize)
{
    // create start text and initialize font
    setFont("font.ttf");

    // press space bar to start
    start.setFont(retro);
    start.setString("Press space bar to start");
    start.setCharacterSize(24); // in pixels, not points!
    start.setFillColor(sf::Color::White);
    start.setStyle(sf::Text::Bold);
    start.setOrigin(start.getGlobalBounds().width / 2, start.getGlobalBounds().height / 2);
    start.setPosition(600,320);

    // create score 1 text and initialize font
    p1score.setFont(retro);
    p1score.setString(std::to_string(GameLogic::getp1Score()));
    p1score.setCharacterSize(40); // in pixels, not points!
    p1score.setFillColor(sf::Color::White);
    p1score.setStyle(sf::Text::Bold);
    start.setOrigin(start.getGlobalBounds().width / 2, start.getGlobalBounds().height / 2);
    p1score.setPosition(20,10);

    // create score 2 text and initialize font
    p2score.setFont(retro);
    p2score.setString(std::to_string(GameLogic::getp2Score()));
    p2score.setCharacterSize(40); // in pixels, not points!
    p2score.setFillColor(sf::Color::White);
    p2score.setStyle(sf::Text::Bold);
    start.setOrigin(start.getGlobalBounds().width / 2, start.getGlobalBounds().height / 2);
    p2score.setPosition(1160,10);
}

void Menu::setFont(std::string fontLocation)
{
    try {
        fs::path execPath = getExecutablePath();
        std::cout << "Executable path: " << execPath << std::endl;

        // Change the working directory to the executable's directory
        fs::current_path(execPath);
        std::cout << "Changed working directory to executable path." << std::endl;

        // Now you can load files relative to the executable's location
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Standard exception: " << e.what() << std::endl;
    }


    if (!retro.loadFromFile(fontLocation)) {
        std::cout << "Font not loaded correctly";
    }
}

void Menu::update()
{
    p1score.setString(std::to_string(GameLogic::getp1Score()));
    p2score.setString(std::to_string(GameLogic::getp2Score()));
}
