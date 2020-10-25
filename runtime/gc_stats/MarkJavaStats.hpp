
/*******************************************************************************
 * Copyright (c) 1991, 2020 IBM Corp. and others
 *
 * This program and the accompanying materials are made available under
 * the terms of the Eclipse Public License 2.0 which accompanies this
 * distribution and is available at https://www.eclipse.org/legal/epl-2.0/
 * or the Apache License, Version 2.0 which accompanies this distribution and
 * is available at https://www.apache.org/licenses/LICENSE-2.0.
 *
 * This Source Code may also be made available under the following
 * Secondary Licenses when the conditions for such availability set
 * forth in the Eclipse Public License, v. 2.0 are satisfied: GNU
 * General Public License, version 2 with the GNU Classpath
 * Exception [1] and GNU General Public License, version 2 with the
 * OpenJDK Assembly Exception [2].
 *
 * [1] https://www.gnu.org/software/classpath/license.html
 * [2] http://openjdk.java.net/legal/assembly-exception.html
 *
 * SPDX-License-Identifier: EPL-2.0 OR Apache-2.0 OR GPL-2.0 WITH Classpath-exception-2.0 OR LicenseRef-GPL-2.0 WITH Assembly-exception
 *******************************************************************************/

#if !defined(MARKJAVASTATS_HPP_)
#define MARKJAVASTATS_HPP_

#include "AtomicOperations.hpp"
#include "JavaStats.hpp"

/**
 * Storage for statistics relevant to the mark phase of a global collection.
 * @ingroup GC_Stats
 */
class MM_MarkJavaStats : public MM_JavaStats {
	/* data members */
private:
protected:
public:
	UDATA _ownableSynchronizerCleared; /**< number of ownable synchronizer objects cleared this cycle */

	UDATA _stringConstantsCleared; /**< The number of string constants that have been cleared during marking */
	UDATA _stringConstantsCandidates; /**< The number of string constants that have been visited in string table during marking */

#if defined(J9MODRON_TGC_PARALLEL_STATISTICS)
	UDATA splitArraysProcessed; /**< The number of array chunks (not counting parts smaller than the split size) processed by this thread */
	UDATA splitArraysAmount;
#endif /* J9MODRON_TGC_PARALLEL_STATISTICS */

	/* function members */
private:
protected:
public:
	void clear();
	void merge(MM_MarkJavaStats* statsToMerge);

	MM_MarkJavaStats() :
		MM_JavaStats()
		, _ownableSynchronizerCleared(0)
		, _stringConstantsCleared(0)
		, _stringConstantsCandidates(0)
	{
		clear();
	}
};

#endif /* MARKJAVASTATS_HPP_ */
