void writeString(int addr, const char* data) {   //функция записи eeprom
  while (*data) {
    EEPROM.write(addr++, *data++);
  }
  EEPROM.write(addr, '\0');   // конец строки
  EEPROM.commit();
}


void readString(int addr, char* buffer, int maxLen) {  //функция чтения eeprom
  int in = 0;
  while (in < maxLen - 1) {
    char c = EEPROM.read(addr + in);
    if (c == '\0' || c == 0xFF) break;
    buffer[in++] = c;
  }
  buffer[in] = '\0';
}