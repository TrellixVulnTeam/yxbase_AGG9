#include "base/strings/string_number_conversions.h"
#include "base/strings/utf_string_conversions.h"
#include "base/process/process_iterator.h"
#include "base/files/file_util.h"
#include "base/files/file_path.h"
#include "base/path_service.h"
#include <iostream>

int main(int argc, const char* const* argv) {

  base::FilePath dir;
  PathService::Get(base::DIR_EXE, &dir);

  std::cout << "compute " << base::UTF16ToUTF8(dir.value()) << " size..." << std::endl;

  int64_t dir_size = base::ComputeDirectorySize(dir);

  std::cout << base::Int64ToString(dir_size) << std::endl;

  int count = base::GetProcessCount(L"notepad.exe", nullptr);
  std::cout << count << std::endl;

  system("pause");
}