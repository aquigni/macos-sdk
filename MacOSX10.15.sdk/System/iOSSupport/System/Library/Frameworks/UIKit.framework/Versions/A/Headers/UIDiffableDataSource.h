#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIDiffableDataSource.h>)
//
//  UIDiffableDataSource.h
//  UIKit
//
//  Copyright © 2018-2019 Apple Inc. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UICollectionView.h>
#import <UIKit/UITableView.h>

NS_ASSUME_NONNULL_BEGIN

// A NSDiffableDataSourceSnapshot represents the complete state of a UI element (e.g. UICollectionView)
//
//    Snapshots can be created in two ways:
//    1. From a connected data source: e.g. UICollectionViewDiffableDataSource.snapshot()
//       This will contain the current state of the UI element.
//
//    2. Constructing a new instance: e.g. NSDiffableDataSourceSnapshot<Int,UUID>()
//       This will construct an empty snapshot with no section or item identifiers.
//
//    Notes:
//      1. All identifiers must be unique. Section and Item identifiers do not overlap and may contain values that exist in the other (i.e. it is OK
//         to have a section identifier == 1 and an item identifier == 1)
//
//      2. If you pass duplicate values in an item or section array (e.g. -appendItemsWithIdentifiers:), the system will throw an exception.
//

UIKIT_EXTERN API_AVAILABLE(ios(13.0),tvos(13.0),watchos(6.0))
@interface NSDiffableDataSourceSnapshot<SectionIdentifierType,ItemIdentifierType> : NSObject<NSCopying>

// structure

@property(nonatomic,readonly) NSInteger numberOfItems;
@property(nonatomic,readonly) NSInteger numberOfSections;
@property(nonatomic,readonly) NSArray<SectionIdentifierType> *sectionIdentifiers;
@property(nonatomic,readonly) NSArray<ItemIdentifierType> *itemIdentifiers;

- (NSInteger)numberOfItemsInSection:(SectionIdentifierType)sectionIdentifier;
- (NSArray<ItemIdentifierType>*)itemIdentifiersInSectionWithIdentifier:(SectionIdentifierType)sectionIdentifier;
- (nullable SectionIdentifierType)sectionIdentifierForSectionContainingItemIdentifier:(ItemIdentifierType)itemIdentifier;

- (NSInteger)indexOfItemIdentifier:(ItemIdentifierType)itemIdentifier;             // If item identifier is not present returns NSNotFound
- (NSInteger)indexOfSectionIdentifier:(SectionIdentifierType)sectionIdentifier;    // If section identifier is not present returns NSNotFound

// items operations

- (void)appendItemsWithIdentifiers:(NSArray<ItemIdentifierType>*)identifiers;     // convenience: appends into last section
- (void)appendItemsWithIdentifiers:(NSArray<ItemIdentifierType>*)identifiers intoSectionWithIdentifier:(SectionIdentifierType)sectionIdentifier;

- (void)insertItemsWithIdentifiers:(NSArray<ItemIdentifierType>*)identifiers beforeItemWithIdentifier:(ItemIdentifierType)itemIdentifier;
- (void)insertItemsWithIdentifiers:(NSArray<ItemIdentifierType>*)identifiers afterItemWithIdentifier:(ItemIdentifierType)itemIdentifier;

- (void)deleteItemsWithIdentifiers:(NSArray<ItemIdentifierType>*)identifiers;
- (void)deleteAllItems;

- (void)moveItemWithIdentifier:(ItemIdentifierType)fromIdentifier beforeItemWithIdentifier:(ItemIdentifierType)toIdentifier;
- (void)moveItemWithIdentifier:(ItemIdentifierType)fromIdentifier afterItemWithIdentifier:(ItemIdentifierType)toIdentifier;

- (void)reloadItemsWithIdentifiers:(NSArray<ItemIdentifierType>*)identifiers;

// section operations

- (void)appendSectionsWithIdentifiers:(NSArray*)sectionIdentifiers;

- (void)insertSectionsWithIdentifiers:(NSArray<SectionIdentifierType>*)sectionIdentifiers beforeSectionWithIdentifier:(SectionIdentifierType)toSectionIdentifier;
- (void)insertSectionsWithIdentifiers:(NSArray<SectionIdentifierType>*)sectionIdentifiers afterSectionWithIdentifier:(SectionIdentifierType)toSectionIdentifier;

- (void)deleteSectionsWithIdentifiers:(NSArray<SectionIdentifierType>*)sectionIdentifiers;

- (void)moveSectionWithIdentifier:(SectionIdentifierType)fromSectionIdentifier beforeSectionWithIdentifier:(SectionIdentifierType)toSectionIdentifier;
- (void)moveSectionWithIdentifier:(SectionIdentifierType)fromSectionIdentifier afterSectionWithIdentifier:(SectionIdentifierType)toSectionIdentifier;

- (void)reloadSectionsWithIdentifiers:(NSArray<SectionIdentifierType>*)sectionIdentifiers;

@end

typedef UICollectionViewCell * _Nullable (^UICollectionViewDiffableDataSourceCellProvider)(UICollectionView * _Nonnull,NSIndexPath * _Nonnull, id _Nonnull);
typedef UICollectionReusableView * _Nullable (^UICollectionViewDiffableDataSourceSupplementaryViewProvider)(UICollectionView* _Nonnull, NSString * _Nonnull, NSIndexPath * _Nonnull);

UIKIT_EXTERN API_AVAILABLE(ios(13.0),tvos(13.0),watchos(6.0))
@interface UICollectionViewDiffableDataSource<SectionIdentifierType,ItemIdentifierType> : NSObject<UICollectionViewDataSource>

- (instancetype)initWithCollectionView:(UICollectionView*)collectionView cellProvider:(UICollectionViewDiffableDataSourceCellProvider)cellProvider;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@property(nonatomic,copy,nullable) UICollectionViewDiffableDataSourceSupplementaryViewProvider supplementaryViewProvider;

// Create a snapshot of the current UICollectionView data source state.
//   This snapshot can be mutated and later applied via -applySnapshot:animatingDifferences:

- (NSDiffableDataSourceSnapshot<SectionIdentifierType,ItemIdentifierType>*)snapshot;

// Apply a snapshot to the collection view committing to the new data source state.
//
//   animatingDifferences == YES: perform a diff between the current UICollectionView state and the snapshot and animate the update.
//   animatingDifferences == NO: commit to the new collection view state from the snapshot. The changes will not be animated.
//
//  Note: you may call this from a background queue which will cause the diff (if needed) to be generated on the calling queue and the
//        final UI update to be applied back on the main queue. However, all applySnapshot invocations must be confined to the same queue.
//        (if you violate this restriction and mix calls between the main queue and some background queue, the framework
//         will log and/or assert to avoid deadlocks)

- (void)applySnapshot:(NSDiffableDataSourceSnapshot<SectionIdentifierType,ItemIdentifierType>*)snapshot animatingDifferences:(BOOL)animatingDifferences;

// convert IndexPath <-> ItemIdentifierType

- (nullable ItemIdentifierType)itemIdentifierForIndexPath:(NSIndexPath*)indexPath;
- (nullable NSIndexPath*)indexPathForItemIdentifier:(ItemIdentifierType)identifier;

@end

typedef UITableViewCell * _Nullable (^UITableViewDiffableDataSourceCellProvider)(UITableView * _Nonnull, NSIndexPath * _Nonnull, id _Nonnull);

UIKIT_EXTERN API_AVAILABLE(ios(13.0),tvos(13.0),watchos(6.0)) 
@interface UITableViewDiffableDataSource<SectionIdentifierType,ItemIdentifierType> : NSObject<UITableViewDataSource>

- (instancetype)initWithTableView:(UITableView*)tableView cellProvider:(UITableViewDiffableDataSourceCellProvider)cellProvider;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

// Create a snapshot of the current UITableView data source state.
//   This snapshot can be mutated and later applied via -applySnapshot:animatingDifferences:

- (NSDiffableDataSourceSnapshot<SectionIdentifierType,ItemIdentifierType>*)snapshot;

// Apply a snapshot to the collection view committing to the new data source state.
//
//   animatingDifferences == YES: perform a diff between the current UITableView  state and the snapshot and animate the update.
//   animatingDifferences == NO: commit to the new collection view state from the snapshot. The changes will not be animated.
//
//  Note: you may call this from a background queue which will cause the diff (if needed) to be generated on the calling queue and the
//        final UI update to be applied back on the main queue. However, all applySnapshot invocations must be confined to the same queue.
//        (if you violate this restriction and mix calls between the main queue and some background queue, the framework
//         will log and/or assert to avoid deadlocks)

- (void)applySnapshot:(NSDiffableDataSourceSnapshot<SectionIdentifierType,ItemIdentifierType>*)snapshot animatingDifferences:(BOOL)animatingDifferences;

// convert IndexPath <-> ItemIdentifierType

- (nullable ItemIdentifierType)itemIdentifierForIndexPath:(NSIndexPath*)indexPath;
- (nullable NSIndexPath*)indexPathForItemIdentifier:(ItemIdentifierType)identifier;

// Default value is UITableViewRowAnimationAutomatic. Change takes effect on the next update.

@property(nonatomic) UITableViewRowAnimation defaultRowAnimation;

@end


NS_ASSUME_NONNULL_END

#else
#import <UIKitCore/UIDiffableDataSource.h>
#endif
