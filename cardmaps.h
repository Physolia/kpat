/***********************-*-C++-*-********

  cardmaps.h  defines pixmaps for playing cards

     Copyright (C) 1995  Paul Olav Tvete

 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted,
 * provided that the above copyright notice appear in all copies and that
 * both that copyright notice and this permission notice appear in
 * supporting documentation.
 *
 * This file is provided AS IS with no warranties of any kind.  The author
 * shall have no liability with respect to the infringement of copyrights,
 * trade secrets or any patents by this file or any part thereof.  In no
 * event will the author be liable for any lost revenue or profits or
 * other special, indirect and consequential damages.

****************************************/

#ifndef P_HACK_CARDMAP
#define P_HACK_CARDMAP

#include "card.h"
//Added by qt3to4:
#include <QPixmap>

class QSvgRenderer;

class cardMap
{
public:

    static cardMap *self();
    explicit cardMap(const QColor &dimcolor);

    static int CARDX();
    static int CARDY();

    static const int NumColors = 4;
    static const int CardsPerColor = 13;

    QPixmap image( Card::Rank _rank, Card::Suit _suit) const;
    QPixmap backSide() const;
    bool setCardDir( const QString &dir);
    bool setBackSide( const QPixmap & _pix, bool scale = true);
    QSvgRenderer *renderer() { return _renderer; }
    double scaleFactor() const;
    double wantedCardSize() const;
    void setWantedCardSize( double w );

private:

    cardMap();
    struct
    {
        QPixmap normal;
    } img[ CardsPerColor ][ NumColors ];
    QPixmap back;
    QColor dimcolor;
    int card_width, card_height;
    QSvgRenderer *_renderer;
    double _wantedCardSize;
    mutable double _scale;

    static cardMap *_self;
};

#endif
