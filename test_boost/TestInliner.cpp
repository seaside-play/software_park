#include "TestInliner.h"

#include <memory>

TestInliner::TestInliner()
    : m_pSelected(nullptr), m_pBackupSelected(nullptr) {}

void TestInliner::BackupNetInfo() {
  if (nullptr == m_pBackupSelected)
    return;

  memcpy(m_pBackupSelected + 1, m_pSelected + 1, 10);
}

void TestInliner::SelectAllNets() {
  memset(m_pSelected + 1, true, 10);
}