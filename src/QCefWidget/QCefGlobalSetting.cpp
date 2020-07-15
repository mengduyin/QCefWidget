#include "QCefGlobalSetting.h"
#include <QCoreApplication>
#include <QDir>
#include <QCefProtocol.h>


CefString QCefGlobalSetting::browser_sub_process_path;
CefString QCefGlobalSetting::resource_directory_path;
CefString QCefGlobalSetting::locales_directory_path;
CefString QCefGlobalSetting::flush_plugin_path;
CefString QCefGlobalSetting::flush_plugin_ver;
CefString QCefGlobalSetting::user_agent;
CefString QCefGlobalSetting::cache_path;
CefString QCefGlobalSetting::user_data_path;
CefString QCefGlobalSetting::locale;
CefString QCefGlobalSetting::accept_language_list;
CefString QCefGlobalSetting::debug_log_path;
int QCefGlobalSetting::persist_session_cookies = 1;
int QCefGlobalSetting::persist_user_preferences = 1;
int QCefGlobalSetting::remote_debugging_port = 0;
bool QCefGlobalSetting::gpu_enabled = true;
bool QCefGlobalSetting::osr_enabled = true;

void QCefGlobalSetting::initializeInstance() { static QCefGlobalSetting s_instance; }

QCefGlobalSetting::QCefGlobalSetting() {
  QDir exeDir = QCoreApplication::applicationDirPath();

  QString strExePath = exeDir.filePath(RENDER_PROCESS_NAME);
  browser_sub_process_path.FromString(QDir::toNativeSeparators(strExePath).toStdString());

  QString strResPath = exeDir.filePath(RESOURCE_DIRECTORY_NAME);
  resource_directory_path.FromString(QDir::toNativeSeparators(strResPath).toStdString());

  QDir ResPath(strResPath);
  locales_directory_path.FromString(
      QDir::toNativeSeparators(ResPath.filePath(LOCALES_DIRECTORY_NAME)).toStdString());

  user_agent.FromString(QCEF_USER_AGENT);

  accept_language_list.FromWString(L"zh-CN,en-US,en,en-GB");
  locale.FromWString(L"zh-CN");

  QString debugLogPath = exeDir.filePath("CEF.log");
  debug_log_path.FromString(QDir::toNativeSeparators(debugLogPath).toStdString());
}

QCefGlobalSetting::~QCefGlobalSetting() {}
