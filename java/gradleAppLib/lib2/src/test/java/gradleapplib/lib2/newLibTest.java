/*
 * This Java source file was generated by the Gradle 'init' task.
 */
package gradleapplib.lib2;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class newLibTest {
    @Test void testConstructor() {
    }

    @Test void testInit() {
        newLib l2 = new newLib();

        assertEquals("newLib init", l2.Init());
    }
}
