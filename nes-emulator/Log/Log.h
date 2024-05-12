//
// Created by kxg220013 on 5/9/2024
// Shamelessly copied from https://github.com/amhndu/SimpleNES/blob/master/include/Log.h
//

#ifndef NES_EMULATOR_LOG_H
#define NES_EMULATOR_LOG_H
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <cstring>

#ifndef __FILENAME__
#define __FILENAME__ __FILE__
#endif

#define LOG(level) \
if (level > nes::Log::get().getLevel()); \
else nes::Log::get().getStream() << '[' << __FILENAME__ << ":" << std::dec << __LINE__ << "] "


namespace nes {
  enum Level {
      None, Error, Info, InfoVerbose, CpuTrace
  };

  class Log {
      Level logLevel;
      std::ostream *m_logStream;
      std::ostream *m_cpuTrace;
  public:
      void setLogStream(std::ostream &stream);
      void setCPUTraceStream(std::ostream &stream);
      Log& setLevel(Level level);
      Level getLevel();

      std::ostream& getStream();
      std::ostream& getCPUTraceStream();

      static Log& get();
  };

  class TeeBuf : public std::streambuf{
      // This tee buffer has no buffer. So every character "overflows"
      // and can be put directly into the teed buffers.
      virtual int overflow(int c);
      // Sync both teed buffers.
      virtual int sync();
      std::streambuf *m_sb1;
      std::streambuf *m_sb2;
  public:
      TeeBuf(std::streambuf *sb1, std::streambuf *sb2);
  };

  class TeeStream : public std::ostream {
      TeeBuf m_tbuf;
  public:
      TeeStream(std::ostream &o1, std::ostream &o2);
  };
}


#endif //NES_EMULATOR_LOG_H
