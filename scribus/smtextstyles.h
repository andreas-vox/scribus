/*
For general Scribus (>=1.3.2) copyright and licensing information please refer
to the COPYING file provided with the program. Following this notice may exist
a copyright and/or license notice that predates the release of Scribus 1.3.2
for which a new license (GPL+exception) is in place.
*/

#ifndef SMTEXTSTYLES_H
#define SMTEXTSTYLES_H

#include "styleitem.h"
#include "styles/styleset.h"

class CharStyle;
class ParagraphStyle;
class ScribusDoc;
class SMCStylePage;
class SMPStyleWidget;

class SMParagraphStyle : public StyleItem
{
	Q_OBJECT
public:
	SMParagraphStyle(StyleSet<CharStyle> *cstyles);
	~SMParagraphStyle();

	QTabWidget* widget();
	QString typeNamePlural();
	QString typeNameSingular();
	void currentDoc(ScribusDoc *doc);
	QValueList<StyleName> styles(bool reloadFromDoc = true);
	void reload();
	void selected(const QStringList &styleNames);
	QString fromSelection() const;
	void toSelection(const QString &styleName) const;
	QString newStyle();
	QString newStyle(const QString &fromStyle);
	void apply();
	void editMode(bool isOn);
	QString shortcut(const QString &stylename) const;
	void setShortcut(const QString &shortcut);
	void deleteStyles(const QValueList<RemoveItem> &removeList);
	void nameChanged(const QString &newName);
	QString getUniqueName(const QString &name);
	void languageChange();
	StyleSet<ParagraphStyle>* tmpStyles(); // butt ugly

signals:
	void selectionDirty();

private:
	SMPStyleWidget *pwidget_;
	ScribusDoc *doc_;
	bool selectionIsDirty_;
	StyleSet<ParagraphStyle> tmpStyles_;
	StyleSet<CharStyle> *cstyles_;
	QValueList<ParagraphStyle*> selection_;
	QValueList<RemoveItem> deleted_;

	void setupConnections();
	void removeConnections();
	void updateStyleList();
	void reloadTmpStyles();
	QValueList<CharStyle> getCharStyles();

private slots:
	// pstyle
	void slotLineSpacingMode(int mode);
	void slotLineSpacing();
	void slotParentDropCap();
	void slotDropCap(bool isOn);
	void slotDropCapLines(int lines);
	void slotDropCapOffset();
	void slotSpaceAbove();
	void slotSpaceBelow();
	void slotAlignment();
	void slotTabRuler();
	void slotLeftIndent();
	void slotRightIndent();
	void slotFirstLine();
	// cstyle
	void slotFontSize();
	void slotEffects(int e);
	void slotEffectProperties();
	void slotFillColor();
	void slotFillShade();
	void slotStrokeColor();
	void slotStrokeShade();
	void slotLanguage();
	void slotScaleH();
	void slotScaleV();
	void slotTracking();
	void slotBaselineOffset();
	void slotFont(QString s);
	void slotParentChanged(const QString &parent);
	void slotCharParentChanged(const QString &parent);
};

class SMCharacterStyle : public StyleItem
{
	Q_OBJECT
public:
	SMCharacterStyle();
	~SMCharacterStyle();

	QTabWidget* widget();
	QString typeNamePlural();
	QString typeNameSingular();
	void currentDoc(ScribusDoc *doc);
	QValueList<StyleName> styles(bool reloadFromDoc = true);
	void reload();
	void selected(const QStringList &styleNames);
	QString fromSelection() const;
	void toSelection(const QString &styleName) const;
	QString newStyle();
	QString newStyle(const QString &fromStyle);
	void apply();
	void editMode(bool isOn);
	QString shortcut(const QString &stylename) const;
	void setShortcut(const QString &shortcut);
	void deleteStyles(const QValueList<RemoveItem> &removeList);
	void nameChanged(const QString &newName);
	QString getUniqueName(const QString &name);
	void languageChange();
	StyleSet<CharStyle>* tmpStyles();

signals:
	void selectionDirty();

private:
	QTabWidget   *widget_;
	SMCStylePage *page_;
	ScribusDoc   *doc_;
	StyleSet<CharStyle> tmpStyles_;
	QValueList<CharStyle*> selection_;
	QValueList<RemoveItem> deleted_;
	bool selectionIsDirty_;

	void reloadTmpStyles();
	void setupConnections();
	void removeConnections();

private slots:
	void slotFontSize();
	void slotEffects(int e);
	void slotEffectProperties();
	void slotFillColor();
	void slotFillShade();
	void slotStrokeColor();
	void slotStrokeShade();
	void slotLanguage();
	void slotScaleH();
	void slotScaleV();
	void slotTracking();
	void slotBaselineOffset();
	void slotFont(QString s);
	void slotParentChanged(const QString &parent);

};

#endif
