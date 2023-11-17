// This is the source code of AyuGram for Desktop.
//
// We do not and cannot prevent the use of our code,
// but be respectful and credit the original author.
//
// Copyright @Radolyn, 2023
#pragma once

#include "lang_auto.h"
#include "ayu/libs/json.hpp"
#include "ayu/libs/json_ext.hpp"
#include "rpl/producer.h"

namespace AyuSettings
{

const auto DEFAULT_ICON = QString("default");

const auto ALT_ICON = QString("alt");

const auto DISCORD_ICON = QString("discord");

const auto SPOTIFY_ICON = QString("spotify");

const auto EXTERA_ICON = QString("extera");

const auto NOTHING_ICON = QString("nothing");

const auto BARD_ICON = QString("bard");

const auto YAPLUS_ICON = QString("yaplus");

class AyuGramSettings
{
public:
	AyuGramSettings()
	{
		// ~ Ghost essentials
		sendReadMessages = true;
		sendReadStories = true;
		sendOnlinePackets = true;
		sendUploadProgress = true;
		sendOfflinePacketAfterOnline = false;

		markReadAfterSend = true;
		markReadAfterReaction = true;
		markReadAfterPoll = true;
		useScheduledMessages = false;

		// ~ Message edits & deletion history
		saveDeletedMessages = true;
		saveMessagesHistory = true;

		// ~ QoL toggles
		disableAds = true;
		disableStories = false;
		disableNotificationsDelay = false;
		localPremium = false;
		copyUsernameAsLink = true;

		// ~ Customization
		appIcon = DEFAULT_ICON;
		simpleQuotesAndReplies = true;
		deletedMark = "🧹";
		editedMark = tr::lng_edited(tr::now);
		recentStickersCount = 50;

		showLReadToggleInDrawer = true;
		showSReadToggleInDrawer = true;
		showGhostToggleInDrawer = true;
		showStreamerToggleInDrawer = false;

		showGhostToggleInTray = true;
		showStreamerToggleInTray = false;

		mainFont = "";
		monoFont = "";

		/*
		 * showPeerId = 0 means no ID shown
		 * showPeerId = 1 means ID shown as for Telegram API devs
		 * showPeerId = 2 means ID shown as for Bot API devs (-100)
		 */
		showPeerId = 2;

		hideAllChatsFolder = false;
		showMessageSeconds = false;

		// ~ Confirmations
		stickerConfirmation = false;
		gifConfirmation = false;
		voiceConfirmation = false;
	}

	bool sendReadMessages;
	bool sendReadStories;
	bool sendOnlinePackets;
	bool sendUploadProgress;
	bool sendOfflinePacketAfterOnline;
	bool markReadAfterSend;
	bool markReadAfterReaction;
	bool markReadAfterPoll;
	bool useScheduledMessages;
	bool saveDeletedMessages;
	bool saveMessagesHistory;
	bool disableAds;
	bool disableStories;
	bool disableNotificationsDelay;
	bool localPremium;
	bool copyUsernameAsLink;
	QString appIcon;
	bool simpleQuotesAndReplies;
	QString deletedMark;
	QString editedMark;
	int recentStickersCount;
	bool showLReadToggleInDrawer;
	bool showSReadToggleInDrawer;
	bool showGhostToggleInDrawer;
	bool showStreamerToggleInDrawer;
	bool showGhostToggleInTray;
	bool showStreamerToggleInTray;
	QString mainFont;
	QString monoFont;
	int showPeerId;
	bool hideAllChatsFolder;
	bool showMessageSeconds;
	bool stickerConfirmation;
	bool gifConfirmation;
	bool voiceConfirmation;

public:
	void set_sendReadMessages(bool val);

	void set_sendReadStories(bool val);

	void set_sendOnlinePackets(bool val);

	void set_sendUploadProgress(bool val);

	void set_sendOfflinePacketAfterOnline(bool val);

	void set_ghostModeEnabled(bool val);

	void set_markReadAfterSend(bool val);

	void set_markReadAfterReaction(bool val);

	void set_markReadAfterPoll(bool val);

	void set_useScheduledMessages(bool val);

	void set_keepDeletedMessages(bool val);

	void set_keepMessagesHistory(bool val);

	void set_disableAds(bool val);

	void set_disableStories(bool val);

	void set_disableNotificationsDelay(bool val);

	void set_localPremium(bool val);

	void set_copyUsernameAsLink(bool val);

	void set_appIcon(QString val);

	void set_simpleQuotesAndReplies(bool val);

	void set_deletedMark(QString val);

	void set_editedMark(QString val);

	void set_recentStickersCount(int val);

	void set_showLReadToggleInDrawer(bool val);

	void set_showSReadToggleInDrawer(bool val);

	void set_showGhostToggleInDrawer(bool val);

	void set_showStreamerToggleInDrawer(bool val);

	void set_showGhostToggleInTray(bool val);

	void set_showStreamerToggleInTray(bool val);

	void set_mainFont(QString val);

	void set_monoFont(QString val);

	void set_showPeerId(int val);

	void set_showMessageSeconds(bool val);

	void set_hideAllChatsFolder(bool val);

	void set_stickerConfirmation(bool val);

	void set_gifConfirmation(bool val);

	void set_voiceConfirmation(bool val);
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE_WITH_DEFAULT(
	AyuGramSettings,
	sendReadMessages,
	sendReadStories,
	sendOnlinePackets,
	sendUploadProgress,
	sendOfflinePacketAfterOnline,
	markReadAfterSend,
	markReadAfterReaction,
	markReadAfterPoll,
	useScheduledMessages,
	saveDeletedMessages,
	saveMessagesHistory,
	disableAds,
	disableStories,
	disableNotificationsDelay,
	localPremium,
	copyUsernameAsLink,
	appIcon,
	simpleQuotesAndReplies,
	deletedMark,
	editedMark,
	recentStickersCount,
	showLReadToggleInDrawer,
	showSReadToggleInDrawer,
	showGhostToggleInDrawer,
	showStreamerToggleInDrawer,
	showGhostToggleInTray,
	showStreamerToggleInTray,
	mainFont,
	monoFont,
	showPeerId,
	showMessageSeconds,
	hideAllChatsFolder,
	stickerConfirmation,
	gifConfirmation,
	voiceConfirmation
);

AyuGramSettings &getInstance();

void load();

void save();

rpl::producer<QString> get_deletedMarkReactive();

rpl::producer<QString> get_editedMarkReactive();

rpl::producer<int> get_showPeerIdReactive();

bool get_ghostModeEnabled();

rpl::producer<bool> get_ghostModeEnabledReactive();

}
