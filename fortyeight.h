/*
 * Copyright (C) 2000-2009 Stephan Kulow <coolo@kde.org>
 *
 * License of original code:
 * -------------------------------------------------------------------------
 *   Permission to use, copy, modify, and distribute this software and its
 *   documentation for any purpose and without fee is hereby granted,
 *   provided that the above copyright notice appear in all copies and that
 *   both that copyright notice and this permission notice appear in
 *   supporting documentation.
 *
 *   This file is provided AS IS with no warranties of any kind.  The author
 *   shall have no liability with respect to the infringement of copyrights,
 *   trade secrets or any patents by this file or any part thereof.  In no
 *   event will the author be liable for any lost revenue or profits or
 *   other special, indirect and consequential damages.
 * -------------------------------------------------------------------------
 *
 * License of modifications/additions made after 2009-01-01:
 * -------------------------------------------------------------------------
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License as
 *   published by the Free Software Foundation; either version 2 of 
 *   the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * -------------------------------------------------------------------------
 */

#ifndef FORTYEIGHT_H
#define FORTYEIGHT_H

#include "dealer.h"


class Fortyeight : public DealerScene
{
    Q_OBJECT

public:
    virtual void initialize();

protected:
    virtual void setGameState( const QString & stream );
    virtual QString getGameState();
    virtual bool checkAdd(const PatPile * pile, const QList<KCard*> & oldCards, const QList<KCard*> & newCards) const;
    virtual bool checkRemove(const PatPile* pile, const QList<KCard*> & cards) const;
    virtual void cardsDroppedOnPile( const QList<KCard*> & cards, KCardPile * pile );
    virtual void restart( const QList<KCard*> & cards );

protected slots:
    virtual bool newCards();

private:
    bool canPutStore( const KCardPile * pile, const QList<KCard*> &cards ) const;

    PatPile *talon;
    PatPile *stack[8];
    PatPile *target[8];
    PatPile *pile;
    bool lastdeal;

    friend class FortyeightSolver;
};

#endif
