//
//  PDFViewController.m
//  PieChart
//
//  Created by Vignesh R on 12/14/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "PDFViewController.h"
#import "BNPieChart.h"
#import "KTOneFingerRotationGestureRecognizer.h"

@implementation PDFViewController

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [NSNumber numberWithInt:10];
    
    KTOneFingerRotationGestureRecognizer *rotateGesture =
    [[KTOneFingerRotationGestureRecognizer alloc] initWithTarget:self action:@selector(handleRotateGesture:)];
    
      
    BNPieChart  *pieView = [BNPieChart pieChartSampleWithFrame:CGRectMake(10, 10, 400, 400) ForData:[NSArray arrayWithObjects:[NSNumber numberWithInt:10],[NSNumber numberWithInt:30],[NSNumber numberWithInt:45],nil]WithLabels:[NSArray arrayWithObjects:@"",@"",@"", nil]];

    [pieView addGestureRecognizer:rotateGesture];
    [rotateGesture release];

    [self.view addSubview:pieView];
	// Do any additional setup after loading the view, typically from a nib.
}
-(IBAction) handleRotateGesture:(KTOneFingerRotationGestureRecognizer *) sender
{
    UIView *view = [sender view];
    [view setTransform:CGAffineTransformRotate([view transform], [sender rotation])];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return YES;
}

@end
