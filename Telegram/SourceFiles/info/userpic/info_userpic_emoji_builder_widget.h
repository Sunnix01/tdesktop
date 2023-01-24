/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

namespace Ui {
class RpWidget;
class VerticalLayout;
} // namespace Ui

namespace Window {
class SessionController;
} // namespace Window

namespace UserpicBuilder {

struct StartData {
	DocumentId documentId = DocumentId(0);
	int colorIndex = 0;
};

struct BothWayCommunication {
	rpl::producer<> triggers;
	Fn<void(QImage &&image)> result;
};

not_null<Ui::VerticalLayout*> CreateUserpicBuilder(
	not_null<Ui::RpWidget*> parent,
	not_null<Window::SessionController*> controller,
	StartData data,
	BothWayCommunication communication);

[[nodiscard]] not_null<Ui::RpWidget*> CreateEmojiUserpic(
	not_null<Ui::RpWidget*> parent,
	const QSize &size,
	rpl::producer<not_null<DocumentData*>> document,
	rpl::producer<int> colorIndex);

} // namespace UserpicBuilder
