// Zum Kompilieren: clang++ test1.cpp -lGLEW -framework OpenGL -lglfw -framework Cocoa -framework IOKit -framework CoreVideo
// Gekuerzt: clang++ test1.cpp -lGLEW -framework OpenGL -lglfw

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main() {

    // Um GLFW benutzen zu koennen muss es zuerst initialisiert werden und am Ende terminiert werden (siehe Ende)
    glfwInit();

    // Wir sagen der Library welche OpenGL Version wir mindestens haben wollen
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Das Fenster soll (vorerst) nicht resizabel sein
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Erstellen des Fensters mit Aufloesung, Titel, nullptr fuer Fenster Mode (sonst glfwGetPrimaryMonitor()) und
    // zusaetzlicher Information
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", nullptr, nullptr); // Windowed

    // Nach Erstellen des Fensters wird der OpenGL Context active gesetzt
    glfwMakeContextCurrent(window);

    // GLEW fuer GPU Treiber Magic
    // Experimental damit moderne Funktionalitaeten unterstuetzt werden
    glewExperimental = GL_TRUE;
    // Initialisieren
    glewInit();

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);

    printf("%u\n", vertexBuffer);

    // Closed event loop: Wird waehrend Programm Ausfuehrung durchlaufen
    while(!glfwWindowShouldClose(window)){

        // Damits nicht crazy rot blinkt
        // Bei aufkommenden Problemen einfach mal das hier auskommentieren
        glClear(GL_COLOR_BUFFER_BIT);

        // Back Buffer (Berechnung) mit Front Buffer (Anzeige) tauschen
        glfwSwapBuffers(window);

        // Event-Abfrage perhaps?
        glfwPollEvents();
    }

    // Falls Vollfenster: Akzeptieren der Esc Taste zum Verlassen
    /*
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    */

    glfwTerminate();

    return 0;

}
