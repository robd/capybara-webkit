#include "SetCookie.h"
#include "WebPage.h"
#include "WebPageManager.h"
#include "NetworkCookieJar.h"
#include <QNetworkCookie>

SetCookie::SetCookie(WebPageManager *manager, QStringList &arguments, QObject *parent) : SocketCommand(manager, arguments, parent) {}

void SetCookie::start()
{
  std::cerr<<"SetCookie:\n";
  QList<QNetworkCookie> cookies = QNetworkCookie::parseCookies(arguments()[0].toLatin1());
  NetworkCookieJar *jar = manager()->cookieJar();
  jar->overwriteCookies(cookies);
  finish(true);
}
