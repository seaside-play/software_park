#pragma once
#include <memory>
class TestInliner {
 public:
  TestInliner();
  inline void BackupNetInfo();
  inline void SelectAllNets();

 private:
  bool* m_pBackupSelected;
  bool* m_pSelected;
};
