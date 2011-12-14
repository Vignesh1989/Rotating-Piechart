//
//  BNPieChart.h
//
//  Created by Tyler Neylon on 10/1/09.
//  Copyleft 2009 Bynomial.
//
//  Bynomial Pie Chart class.
//  A UIView subclass to draw a pie chart.
//  Automatically handles positioning of labels and the chart within the frame.
//  Also provides color coding and a snazzy-looking pie for you.
//
//  Sample usage:
//   PieChart* chart = [[PieChart alloc] initWithFrame:myFrame];
//   [chart addSlicePortion:0.35 withName:@"Yes"];
//   [chart addSlicePortion:0.40 withName:@"No"];
//   [chart addSlicePortion:0.25 withName:@"Maybe"];  // portions add to 1.0
//   [mySuperview addSubview:chart];
//

#import <UIKit/UIKit.h>

@protocol PieChartDelegate

-(void)pieViewTouchedAtIndex:(int) index;

@end

@interface BNPieChart : UIView {
		
@private
	
	// Variables useful for drawing.  (Avoid recomputing them too much.)
	CGFloat centerX;
	CGFloat centerY;
	CGFloat radius;
  
  // strong [All objects are retained.]
	
	// Each element is an NSNumber representing a float.
	// The values add up to 1.0.
	NSMutableArray* slicePortions;	
	
	// Endpoints of the slices.  Always has size one more than slicePortions.
	NSMutableArray* slicePointsIn01;
	
	NSMutableArray* sliceNames;
	NSMutableArray* nameLabels;
	
	CGColorSpaceRef colorspace;
	
	int fontSize;
	
	NSMutableArray *sliceRadianRangeArray;
	
	//Delegate object
	id <PieChartDelegate> pieDelegate;
}

@property (nonatomic, retain) NSMutableArray* slicePortions;
@property (nonatomic, retain) NSMutableArray *sliceRadianRangeArray;
@property (nonatomic, retain) id <PieChartDelegate> pieDelegate;

// Adds a slice with the given portion (fraction in the range 0.0-1.0),
// and name.  The name may be nil.
- (void)addSlicePortion:(float)slicePortion withName:(NSString *)name;

// Creates a sample pie chart in the given frame.
+ (BNPieChart *)pieChartSampleWithFrame:(CGRect)frame  ForData:(NSArray *)values WithLabels:(NSArray *)labels;
- (id)initWithFrame:(CGRect)frame  ForData:(NSArray *)values WithLabels:(NSArray *)labels;

@end
