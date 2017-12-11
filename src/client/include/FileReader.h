#ifndef REVERSI_FILEREADER_H
#define REVERSI_FILEREADER_H

class FileReader {
 public:
  //constructor
  FileReader(const char* path);
  // Reading our clients config file
  const char* readConfigFile(int *port)

 private:
  const char* path;
};

#endif //REVERSI_FILEREADER_H
